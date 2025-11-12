#include<bits/stdc++.h>
using namespace std;
struct bi{
	int a,b,c;
}v[100007];
int q[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		int C[100007],p=0;
		int h=0,n,aa=0,bb=0,cc=0;
		int at=20007,bt=20007,ct=20007;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i].a>>v[i].b>>v[i].c;
			if(v[i].a>v[i].b&&v[i].a>v[i].c){
				aa++;
				h+=v[i].a;
			}
			else if(v[i].b>v[i].c){
				bb++;
				h+=v[i].b;
			}
			else{
				cc++;
				h+=v[i].c;
			}
		}
		if(bb>n/2){
			swap(aa,bb);
			for(int i=1;i<=n;i++){
				swap(v[i].a,v[i].b);
			}
		}
		if(cc>n/2){
			swap(aa,cc);
			for(int i=1;i<=n;i++){
				swap(v[i].a,v[i].c);
			}
		}
		if(aa>n/2){
			for(int i=1;i<=n;i++){
				if(v[i].a>v[i].b&&v[i].a>v[i].c){
					C[++p]=min(v[i].a-v[i].b,v[i].a-v[i].c);
				}
			}
			sort(C+1,C+aa+1);
			for(int i=1;i<=aa-n/2;i++){
				h-=C[i];
			}
		}
		cout<<h<<endl;
	}
	return 0;
}
