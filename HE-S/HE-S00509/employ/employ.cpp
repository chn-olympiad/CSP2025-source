#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cnt=1;
	for (long long i=2;i<=n;i++){
		n*=i;
		n%=998244353;
	}
	cout << n;
	fclose(stdin);
	fclose(stdout);
  /*666 wo zhen de shi xie bu dong le;
	yi lun S zu cheng ji dou suan xuan de;
	wo ke hu chui bu guo zhe si dao ti;
	sui bian xie le ge jie cheng jia qu yu;
	gei wo beng ba;
	zhe xie zhi shi cou zi jie shu de;
	rang ta de cheng du kan qi lai he qun...;
	jiu zhe yang ba;
	wu wu wu;
	*/
	return 0;
}
