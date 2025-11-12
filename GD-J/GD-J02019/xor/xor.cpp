#include<iostream>
#include<algorithm>
using namespace std;
long long a=0,b=0,t=0,zw=0,ans=0;
string o[500005];
struct ll{
	long long started,endd;
};
ll ji[500005];
void er(long long ji,long long s){
	string omg="";
	while(s){
		omg+=char(s%2+48);
		s/=2;
	}
	for(int i=omg.size()-1;i>=0;i--){
		o[ji]+=omg[i];
	}
	if(omg=="") o[ji]="0";
	return;
}
string yi(string a1,string a2){
	string yi="",a3="",a4="";
	for(int i=0;i<max(a1.size(),a2.size());i++){
		if(a1.size()<=a2.size()){
			if(i<a2.size()-a1.size()){
				a3+='0';a4+=a2[i];
			}
			else{
				a3+=a1[i-a2.size()+a1.size()];a4+=a2[i];
			}
		}
		else{
			if(i<a1.size()-a2.size()){
				a4+='0';a3+=a1[i];
			}
			else{
				a4+=a2[i-a1.size()+a2.size()];a3+=a1[i];
			}
		}
	}
	for(int i=0;i<a3.size();i++){
		if(a3[i]==a4[i]) yi+='0';
		else if(a3[i]!=a4[i]) yi+='1';
	}
	string p="";
	bool pan=false;
	for(int i=0;i<yi.size();i++){
		if(yi[i]=='1'||pan){
			pan=true;
			p+=yi[i];
		}
	}
	return p;
}
long long huan(string z){
	long long zen=1,zs=0;
	for(int i=z.size()-1;i>=0;i--){
		zs+=zen*int(z[i]-48);
		zen*=2;
	}
	return zs;
}
bool cmp(ll a,ll b){
	if(a.endd==b.endd) return a.started<b.started;
	return a.endd<b.endd;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>t;
		er(i,t);
	}
	string z="";
	for(int i=1;i<=a;i++){
		z="";
		for(int j=i;j<=a;j++){
			if(z=="") z=o[j];
			else z=yi(z,o[j]);
			if(huan(z)==b){
				zw++;
				ji[zw].started=i;ji[zw].endd=j;
			}
		}
	}
	sort(1+ji,1+ji+zw,cmp);
	long long ended=-1;
	for(int i=1;i<=zw;i++){
		if(ji[i].started>ended){
			ans++;
			ended=ji[i].endd;
		}
	}
	cout<<ans;
	return 0;
}
