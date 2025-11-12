#include <bits/stdc++.h>
using namespace std;
struct Node{
	int a1,a2,a3,max1,max2,max3;
}p[100005];
int t;
int b1,b2,b3;
long long ans=0;
bool cmp1(Node a,Node b){
	return b.max1-b.max2<a.max1-a.max2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		int n;
		cin>>n;
		int q=n/2;
		for(int i=0;i<n;i++){
			cin>>p[i].a1>>p[i].a2>>p[i].a3;
			p[i].max1=max(max(p[i].a1,p[i].a2),p[i].a3);
			if((p[i].a1>p[i].a2&&p[i].a2>p[i].a3)||(p[i].a3>p[i].a2&&p[i].a2>p[i].a1)){
				p[i].max2=p[i].a2;
			}
			else if((p[i].a1>p[i].a3&&p[i].a3>p[i].a2)||(p[i].a2>p[i].a3&&p[i].a3>p[i].a1)){
				p[i].max2=p[i].a3;
			}
			else{
				p[i].max2=p[i].a1;
			}
			p[i].max3=min(min(p[i].a1,p[i].a2),p[i].a3);
		}
		sort(p,p+n,cmp1);
		for(int i=0;i<n;i++){
			if(p[i].max1==p[i].a1){
				if(b1==q){
					if(p[i].max2==p[i].a1){
						if(p[i].max3==p[i].a2){
							ans+=p[i].a2;
							b2++;
						}
						if(p[i].max3==p[i].a3){
							ans+=p[i].a3;
							b3++;
						}
					}
					else if(p[i].max2==p[i].a2){
						b2++;
						ans+=p[i].a2;		
					}
					else{
						b3++;
						ans+=p[i].a3;
					}
				}
				else{
					ans+=p[i].a1;
					b1++;	
				}
			}
			else if(p[i].max1==p[i].a2){
				if(b2==q){
					if(p[i].max2==p[i].a2){
						if(p[i].max3==p[i].a1){
							ans+=p[i].a1;
							b1++;
						}
						if(p[i].max3==p[i].a3){
							ans+=p[i].a3;
							b3++;
						}
					}
					else if(p[i].max2==p[i].a3){
						b3++;
						ans+=p[i].a3;
					}
					else{
						b1++;
						ans+=p[i].a1;
					}
				}
				else{
					ans+=p[i].a2;
					b2++;
				}
				
			}
			else{
				if(b3==q){
					if(p[i].max2==p[i].a3){
						if(p[i].max3==p[i].a1){
							ans+=p[i].a1;
							b1++;
						}
						if(p[i].max3==p[i].a2){
							ans+=p[i].a2;
							b2++;
						}
					}
					else if(p[i].max2==p[i].a2){
						b2++;
						ans+=p[i].a2;
					}
					else{
						b1++;
						ans+=p[i].a1;
					}
				}
				else{
					ans+=p[i].a3;
					b3++;	
				}
			}
		}
//		cout<<b1<<' '<<b2<<' '<<b3<<endl;

		cout<<ans<<endl;
		b1=0,b2=0,b3=0;
	}
	return 0;
}
