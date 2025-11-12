#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mo=998244353;
int n;
int num[N];
long long dps(int no,int ha,int ne,long long su){
	if(ha>=ne){
		if(num[no]*2>=su)return 0;
		return 1;
	}
	long long ans=0;
	for(int i = no+1;i<=n;i++){
		ans+=dps(i,ha+1,ne,su+num[i]);
		ans%=mo;
	}
	return ans;
}
void so1(){
	long long li,ans=0;
	for(int i = 3;i<=n;i++){
	//	for(int j = 1;j<=n;j++){
			li=dps(0,0,i,0);
	//		cout<<li<<" ";
			ans+=li;
	//		cout<<ans<<"\n";
			ans%=mo;
	//	}
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	bool flag=1;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>num[i];
		if(num[i]!=1){
			flag=0;
		}
	}
	sort(num+1,num+1+n);
	//if(n<=20){
		so1();
//	}
	long long ans=0;
//	string b="";
//	while(ta.size()){
//		b+=ta.top();
//		ta.pop();
//	}
//	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
