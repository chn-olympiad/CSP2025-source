#include<bits/stdc++.h>//高精？ 
using namespace std;
const int N = 5e3+10;
const long long mod = 998225353;
long long ans;
int n;
int num[N];
//choose[i][j] = 从1选到i,最大值为j的所有方案总和数 
bool cho[N];
long long choose[N][N];
struct str{
	long long fan;
	long long cdh;
};
long long ann(int a,int b){//排列 
	long long ans = 1;
	for(int i = b;b - i < a;i--){
		ans*=i;
		ans%=mod;
	}
	return ans;
}
long long cnn(){//组合
	long long ans;
	for(int i = n;i >= 3;i--){
		ans += ann(i,n) / ann(i,i);
	}
	return ans;
}
/*str qpl(long long number,bool chod[N],int cs){
	int fa = 0;
	int cd = 0;
	for(int i = 1;i <= number;i++){
		if(chod[i] == 1){
			cd += num[i];
		}
	}
	for(int i = 1;i < number;i++){
		chod[i] = 1;
		str g = qpl(i,chod,cs+1);
		if(g.cdh <= cd)continue;
		else return g.fan;
		chod[i] = 0;
	}
	if(cs == 1){
		return {}
	}
	return {fa,cd};
}*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	bool flag = 0;
	for(int i = 1;i <= n;i++){
		cin>>num[i];
		if(num[i] != 1){
			flag = 1;
		}
	}
	if(flag == 0){
		cout<<cnn();
		return 0;
	}
	
	sort(num+1,num+n+1);
	/*for(int i = 3;i <= n;i++){
		ans += qpl(i,,1) % mod;
	}*/
	cout<<ans;
	return 0;
}
