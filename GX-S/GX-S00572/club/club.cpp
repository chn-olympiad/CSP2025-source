#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,b[4],maxx=-1;
		cin>>n;
		int a[100100][3];
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		vector<int> sum;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n-1;j++){
				int k=n-i-j;
				for(int f=1;f<=i;f++)sum.push_back(1);
				for(int f=1;f<=j;f++)sum.push_back(2);
				for(int f=1;f<=k;f++)sum.push_back(3);
				for(int i=1;i<=n;i++)cout<<sum[i];
				cout<<endl;
				do{
					int num=0;
					for(int h=1;h<=n;h++){
						if(b[sum[h]]>n/2){break;num=0;}
						else{
							b[sum[h]]++;
							num+=a[h][sum[h]];
						}
					}
					maxx=max(maxx,num);
					for(int h=1;h<=3;h++)b[h]=0;
				}while(next_permutation(sum.begin(),sum.end()));
			}
		}
		cout<<maxx<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
