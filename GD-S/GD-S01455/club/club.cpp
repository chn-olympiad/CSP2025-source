#include<bits/stdc++.h>
using namespace std;
struct stu{
	long a,b,c;
}l[100005];
bool cmp(stu x,stu y){
	if(x.a==y.a){
		if(x.b==y.b)return x.c>y.c;
		return x.b>y.b;
	}
	return x.a>y.a;
}
long t,n,s,c[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>l[i].a>>l[i].b>>l[i].c;
		sort(l,l+n,cmp);
		for(int i=0;i<n;i++){
			if(l[i].a>l[i].b&&l[i].a>l[i].c){
				if(c[0]<n/2){
					s+=l[i].a;c[0]++;
				}else s+=max(l[i].b,l[i].c);
			}else if(l[i].b>l[i].a&&l[i].b>l[i].c){
				if(c[1]<n/2){
					s+=l[i].b;c[1]++;
				}else s+=max(l[i].a,l[i].c);
			}else{
				if(c[2]<n/2){
					s+=l[i].c;c[2]++;
				}else s+=max(l[i].a,l[i].b);
			}
		}
		cout<<s<<endl;
		c[0]=c[1]=c[2]=s=0;
	}
}
