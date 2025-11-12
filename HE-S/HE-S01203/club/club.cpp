#include <bits/stdc++.h>
using namespace std;
struct node{int a,b,c;};
int t;
const int N=1e5+10;
node s[N];
int a[N],b[N],c[N];
bool cmp(node ef,node es){
	return ef.a>es.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int cs=1;cs<=t;cs++){ 
		int n;
		int acut=1,bcut=1,ccut=1;
		scanf("%d",&n);
		bool pf=true;
		for(int i=1;i<=n;i++){scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);if(!(s[i].b==s[i].c&&s[i].b==0)) pf=false;}
		if(pf){
			sort(s+1,s+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=s[i].a;
			}
			cout <<sum<<endl;
		}
		else{	
			for(int i=1;i<=n;i++){
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
				a[acut]=i;
				acut++;
			}
			else if(s[i].b>=s[i].a&&s[i].b>=s[i].c){
				b[bcut]=i;
				bcut++;
			}
			else if(s[i].c>=s[i].b&&s[i].c>=s[i].a){
				c[ccut]=i;
				ccut++;
			}
		}
		
		sort(a+1,a+acut+1,greater<int>());
		sort(b+1,b+bcut+1,greater<int>());
		sort(c+1,c+ccut+1,greater<int>());
		if(acut>n/2){
			for(int j=acut;j>n/2;j--){
				if(s[a[j]].b>s[a[j]].c&&bcut<n/2){
					bcut++;
					b[bcut]=s[a[j]].b;
					a[j]=0;
					acut--;
				}
				else if(s[a[j]].c>s[a[j]].b&&ccut<n/2){
					ccut++;
					c[ccut]=s[a[j]].c;
					a[j]=0;
					acut--;
				}
				else if(bcut>=ccut&&bcut<n/2){
					bcut++;
					b[bcut]=s[a[j]].b;
					a[j]=0;
					acut--;
				}
				else if(ccut>bcut&&ccut<n/2){
					ccut++;
					c[ccut]=s[a[j]].c;
					a[j]=0;
					acut--;
				}
			}
			sort(b+1,b+bcut+1,greater<int>());
			sort(c+1,c+ccut+1,greater<int>());
		}
		if(bcut>n/2){
			for(int j=bcut;j>n/2;j--){
				if(s[b[j]].a>s[b[j]].c&&acut<n/2){
					acut++;
					a[acut]=s[b[j]].a;
					b[j]=0;
					bcut--;
				}
				else if(s[b[j]].c>s[b[j]].a&&ccut<n/2){
					ccut++;
					c[ccut]=s[b[j]].c;
					b[j]=0;
					bcut--;
				}
				else if(acut>ccut&&acut<n/2){
					acut++;
					a[acut]=s[b[j]].a;
					b[j]=0;
					bcut--;
				}
				else if(ccut>=acut&&ccut<n/2){
					ccut++;
					c[ccut]=s[b[j]].c;
					b[j]=0;
					bcut--;
				}
			}
			sort(a+1,a+acut+1,greater<int>());
			sort(c+1,c+ccut+1,greater<int>());
		}
		if(ccut>n/2){
			for(int j=ccut;j>n/2;j--){
				if(s[c[j]].b>s[c[j]].a&&bcut<n/2){
					bcut++;
					b[bcut]=s[c[j]].b;
					c[j]=0;
					ccut--;
				}
				else if(s[c[j]].a>s[c[j]].b&&acut<n/2){
					acut++;
					a[acut]=s[c[j]].a;
					c[j]=0;
					ccut--;
				}
				else if(bcut>acut&&bcut<n/2){
					bcut++;
					b[bcut]=s[c[j]].b;
					c[j]=0;
					ccut--;
				}
				else if(acut>=bcut&&acut<n/2){
					acut++;
					a[acut]=s[c[j]].a;
					c[j]=0;
					ccut--;
				}
			}
			sort(b+1,b+bcut+1,greater<int>());
			sort(a+1,a+acut+1,greater<int>());
		}
		int sum=0;
		for(int i=1;i<=acut;i++) sum+=s[a[i]].a;
		for(int i=1;i<=bcut;i++) sum+=s[b[i]].b;
		for(int i=1;i<=ccut;i++) sum+=s[c[i]].c;
		cout << sum << endl;
		}
	}
	return 0;
}
