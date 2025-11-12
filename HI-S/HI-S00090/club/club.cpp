#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,lie,hang;
};
bool cmp(node x,node y){
	return x.num>y.num;
}
node a[300005];
int s[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int n,ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[(i*3)+1].num;
			cin>>a[(i*3)+2].num;
			cin>>a[(i*3)+3].num;
			a[(i*3)+1].hang=i+1;
			a[(i*3)+2].hang=i+1;
			a[(i*3)+3].hang=i+1;
			a[(i*3)+1].lie=1;
			a[(i*3)+2].lie=2;
			a[(i*3)+3].lie=3;
		}
		sort(a+1,a+3*n+1,cmp);
		for(int i=1;i<=3*n;i++){
			memset(s,0,sizeof(s));
			int num1=0,num2=0,num3=0,numz=0;
			if(a[i].lie==1){
				num1++;
			}
			if(a[i].lie==2){
				num2++;
			}
			if(a[i].lie==3){
				num3++;
			}
			numz+=a[i].num;
			s[a[i].hang]=1;
			for(int j=1;j<=3*n&&num1+num2+num3<n;j++){
				if(s[a[j].hang]==0){
					if(a[j].lie==1){
						if(num1<n/2){
							numz+=a[j].num;
							//cout<<numz<<"\n";
							num1++;
						}
					}
					else if(a[j].lie==2){
						if(num2<n/2){
							numz+=a[j].num;
							//cout<<numz<<"\n";
							num2++;
						}
					}
					else if(a[j].lie==3){
						if(num3<n/2){
							numz+=a[j].num;
							//cout<<numz<<"\n";
							num3++;
						}
					}
					s[a[j].hang]=1;
				}
				
			}
			ans=max(ans,numz);
			
		}
//		for(int i=1;i<=3*n;i++){
//				cout<<a[i].num<<" ";
//			}
//			cout<<"\n";
		cout<<ans<<"\n";
	}
	
	return 0;
}
