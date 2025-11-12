#include<bits/stdc++.h>
using namespace std;
int t,n;
int num1,num2,num3;
int a[100001][4]={0};
bool one[100001]={0};
bool two[100001]={0};
bool three[100001]={0};
int w[50001]={0};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int sum=0;
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		num1=0;
		num2=0;
		num3=0;
		for(int i=1;i<=n;i++){
			int q=max(a[i][1],max(a[i][2],a[i][3]));
			sum+=q;
			if(q==a[i][1]){
				one[i]=1;
				num1++;
			} else if(q==a[i][2]){
				two[i]=1;
				num2++;
			} else{
				three[i]=1;
				num3++;
			}
		}	
		int count=0;
		if(num1>(n/2)){
			for(int i=1;i<=n;i++){
				if(one[i]==1){
					count++;
					w[count] = a[i][1]-max(a[i][2],a[i][3]);
//					cout<<count<<" "<<i<<" "<<w[count]<<endl;
				}
			}
			sort(w+1,w+count+1);
			for(int i=1;i<=num1-n/2;i++){
//				cout<<w[i]<<" ";
				sum-=w[i];
			}
		}else if(num2>(n/2)){
			for(int i=1;i<=n;i++){
				if(two[i]==1){
					count++;
					w[count] = a[i][2]-max(a[i][1],a[i][3]);
//					cout<<count<<" "<<i<<" "<<w[count]<<endl;
				}
			}
			sort(w+1,w+count+1);
			for(int i=1;i<=num2-n/2;i++){
//				cout<<w[i]<<" ";
				sum-=w[i];
			}
		}else if(num3>(n/2)){
			for(int i=1;i<=n;i++){
				if(three[i]==1){
					count++;
					w[count] = a[i][3]-max(a[i][2],a[i][1]);
//					cout<<count<<" "<<i<<" "<<w[count]<<endl;
				}
			}
			sort(w+1,w+count+1);
			for(int i=1;i<=num3-n/2;i++){
//				cout<<w[i]<<" ";
				sum-=w[i];
			}
		}
		cout<<sum<<endl;
	}
} 
