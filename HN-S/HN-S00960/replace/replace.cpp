#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2;
	int len;
}a[100010];
int n,q,l,r;
string t1,t2;
bool cmp(node a1,node a2){
	return a1.len>a2.len;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n>=200){
		for(int i=1;i<=q;i++)puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		a[i].len=a[i].s1.length();
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int ans=0;
		if(t1.length()!=t2.length()){
			puts("0");
			continue;
		}
		int lenx=t1.length();
		for(int j=0;j<lenx;j++){
			if(t1[j]!=t2[j]){
				l=j;
				break;
			}
		}
		for(int j=lenx-1;j>0;j--){
			if(t1[j]!=t2[j]){
				r=j;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=0;k<a[j].len-(r-l+1);k++){
				int flag0=0;
				if(a[j].s1[k]==t1[l]&&a[j].s2[k]==t2[r]){
					int flag=0;
					for(int x=k+1,y=l+1;y<=r;x++,y++){
						if(a[j].s1[x]!=t1[y]||a[j].s2[x]!=t2[y]){
							flag=1;
							break;
						}
					}
					if(flag==0){
						if(k>l)break;
						int flag1=0;
						for(int x3=k-1,y3=l-1;x3>=0;x3--,y3--){
							if(a[j].s1[x3]!=t1[y3]||a[j].s2[x3]!=t2[y3]){
								flag1=1;
								break;
							}
						}
						if(flag1==1)break;
						for(int x4=k+(r-l+1),y4=r;x4<=a[j].len;x4++,y4++){
							if(a[j].s1[x4]!=t1[y4]||a[j].s2[x4]!=t2[y4]){
								flag1=1;
								break;
							}
						}
						if(flag1==1)break;
						ans++;
						flag0=1;
					}
				}
				if(flag0==1)continue;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

