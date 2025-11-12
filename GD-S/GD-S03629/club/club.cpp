#include<bits/stdc++.h>
using namespace std;
const int k=10e5+1;
struct Node{
	int a1=0,a2=0,a3=0;
}a[k];
bool cmp1(Node x1,Node y1){
	return x1.a1<y1.a1;
}
bool cmp2(Node x2,Node y2){
	return x2.a2<y2.a2;
}
bool cmp3(Node x3,Node y3){
	return x3.a3<y3.a3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
	int club1=0,club2=0,club3=0;
		int ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		for(int i=1;i<=n;i++){
			if(i%3==1){
				sort(a+1,a+n+1,cmp1);
				if(club1+1<=n/2,cmp1){
					if(a[n].a1!=0){
						ans+=a[n].a1;
						a[n].a1=0;
						a[n].a2=0;
						a[n].a3=0;
						club1++;
					}					
				}
			}else if(i%3==2){
				sort(a+1,a+n+1,cmp2);
				if(club2+1<=n/2){
					if(a[n].a2!=0){
						ans+=a[n].a2;
						a[n].a1=0;
						a[n].a2=0;
						a[n].a3=0;
						club2++;
					}
				}
			}else{
				sort(a+1,a+n+1,cmp3);
				if(club3+1<=n/2){
					if(a[n].a3!=0){
						ans+=a[n].a3;
						a[n].a1=0;
						a[n].a2=0;
						a[n].a3=0;
						club3++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
