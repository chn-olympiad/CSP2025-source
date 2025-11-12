#include <bits/stdc++.h>
using namespace std;
int tot1,tot2,tot3,sum_pro=0,sum_pro1=0,sum_pro2=0;
const int N=100005;
int ai1[N],ai2[N],ai3[N];
int score_1[N],score_2[N],score_3[N];
int max_tot[N];
int f(int a,int b,int c){
	int p=max(a,b);
	return max(p,c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,sum1=0,sum2=0,sum3=0;
	int n;
	cin>>t;
	if(t==1){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ai1[i]>>ai2[i]>>ai3[i];
			max_tot[i]=f(ai1[i],ai2[i],ai3[i]);
			if(max_tot[i]==ai1[i]){
				score_1[i]++;
			}
			if(max_tot[i]==ai2[i]){
				score_2[i]++;
			}
			if(max_tot[i]==ai3[i]){
				score_3[i]++;
			}
			sum1+=score_1[i]; 
			sum2+=score_2[i];
			sum3+=score_3[i];
			score_1[i]=0;
			score_2[i]=0;
			score_3[i]=0;
			tot1+=sum1;
			tot2+=sum2;
			tot3+=sum3;
			if(tot1<=n/2&&tot2<=n/2&&tot3<=n/2){
				sum_pro+=max_tot[i];
			}
			cout<<sum_pro<<endl;
			sum1=0;
			sum2=0;
			sum3=0;
			
		}
	}
	return 0;
} 	
