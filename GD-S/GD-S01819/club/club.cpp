#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
};
node a[100100];
int t;
int n;
bool cmp(node x,node y){
	if(x.a<x.b)swap(x.a,x.b);
	if(x.b<x.c)swap(x.b,x.c);
	if(x.a<x.b)swap(x.a,x.b);	 
	if(y.a<y.b)swap(y.a,y.b);
	if(y.b<y.c)swap(y.b,y.c);
	if(y.a<y.b)swap(y.a,y.b);	
	return x.a-x.b>y.a-y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		long long s=0;
		vector<node> v;
		sort(a+1,a+n+1,cmp);
		int ca=0,cb=0,cc=0;
		for(int i=1;i<=n;i++){
			if(a[i].b>a[i].a&&a[i].b>a[i].c){
				if(cb==n/2){
					if(a[i].a>a[i].c){
						ca++;
						s+=a[i].a;
					}else{
						cc++;
						s+=a[i].c;
					}
				}else{
					cb++;
					s+=a[i].b;
				}
			}else if(a[i].c>a[i].a&&a[i].b<a[i].c){
				if(cc==n/2){
					if(a[i].a>a[i].b){
						ca++;
						s+=a[i].a;
					}else{
						cb++;
						s+=a[i].b;
					}
				}else{
					cc++;
					s+=a[i].c;
				}
			}else if(a[i].c<a[i].a&&a[i].b<a[i].a){
				if(ca==n/2){
					if(a[i].c>a[i].b){
						cc++;
						s+=a[i].c;
					}else{
						cb++;
						s+=a[i].b;
					}
				}else{
					ca++;
					s+=a[i].a;
				}				
			}else{
				v.push_back(a[i]);
			}
		}
		for(int i=0;i<v.size();i++){
			if(v[i].a==v[i].b){
				if(ca<cb){
					ca++;
					s+=v[i].a; 
				}else{
					cb++;
					s+=v[i].b;
				}
			}else if(v[i].a==v[i].c){
				if(ca<cc){
					ca++;
					s+=v[i].a; 
				}else{
					cc++;
					s+=v[i].c;
				}				
			}else{
				if(cc<cb){
					cc++;
					s+=v[i].c; 
				}else{
					cb++;
					s+=v[i].b;
				}				
			}
		}
		
		cout<<s<<endl;
	}
	return 0;
} 
