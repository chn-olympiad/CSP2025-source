#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=1e5+10;
struct employees{
	long long a1,a2,a3;
}a[maxn];
long long  differ12[maxn];
long long differ13[maxn];
long long differ23[maxn];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			differ12[i]=abs(a[i].a1-a[i].a2);
			differ13[i]=abs(a[i].a1-a[i].a3);
			differ23[i]=abs(a[i].a2-a[i].a3);
		}
			long long sum=0;
			long long firstn=0,secondn=0,thirdn=0;
			for(int i=1;i<=n;i++){
				if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
					sum+=a[i].a1;
					firstn++;
				}
				else if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3){
					sum+=a[i].a2;
					secondn++;
				}
				else{
					sum+=a[i].a3;
					thirdn++;
				}
			}
			cout<<firstn<<" "<<secondn<<" "<<thirdn<<endl;
			sort(differ12+1,differ12+1+n); 
			sort(differ13+1,differ13+1+n);
			sort(differ23+1,differ23+1+n);
			int count1=1;
			while(firstn>n/2){
				if((differ12[count1]<=differ13[count1]&&secondn+1<=n/2)||thirdn+1>n/2){
					secondn++;
					firstn--;
					sum-=differ12[count1];
					count1++;
				}
				else{
					thirdn++;
					firstn--;
					sum-=differ13[count1];
					count1++;
				}
			}
			count1=1;
			while(secondn>n/2){
				if((differ12[count1]<=differ23[count1]&&firstn+1<=n/2)||thirdn+1>n/2){
					firstn++;
					secondn--;
					sum-=differ12[count1];
					count1++;
				}
				else{
					thirdn++;
					secondn--;
					sum-=differ23[count1];
					count1++;
				}
			}
			count1=1;
			while(thirdn>n/2){
				if((differ13[count1]<=differ23[count1]&&firstn+1<=n/2)||secondn+1>n/2){
					firstn++;
					thirdn--;
					sum-=differ13[count1];
					count1++;
				}
				else{
					secondn++;
					thirdn--;
					sum-=differ23[count1];
					count1++;
				}
			}
			cout<<firstn<<" "<<secondn<<" "<<thirdn<<endl;
			cout<<sum<<endl;
		}
		
		
		
	
	
	
	
	
	
	
	
	
	return 0;
} 
