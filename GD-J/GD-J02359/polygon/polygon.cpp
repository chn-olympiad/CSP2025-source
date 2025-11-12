#include<bits/stdc++.h>
using namespace std;
const long long WYNN_MOD=998244353;
long long Sticks[1005],ans_count;
int n;
//完啦，死马当活马医吧 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>Sticks[i];
	sort(Sticks+1,Sticks+n+1);
	int TEMP_sum=0;
	for(int i=1;i<=n;i++){
		TEMP_sum=0;
		for(int j=i;j<=n;j++){
			TEMP_sum+=Sticks[j];
			if(TEMP_sum>Sticks[i]+Sticks[i+1] && TEMP_sum>2*Sticks[j])ans_count++;
		}
	}
	cout<<ans_count<<endl;
	return 0;
}
