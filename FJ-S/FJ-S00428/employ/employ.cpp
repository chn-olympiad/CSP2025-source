#include <iostream>

using namespace std;

long long ans = 0,n,prac[100005],want;
bool ques[100005],matched[100005];

void f(long long x,long long count,long long in){
	matched[x] = true;
	bool flag = true;
	for(long long i = 0;i < n;i++){
		if(matched[i]==false){
			flag=false;
			break;
		}
	}
	if(count > prac[x] || ques[x] == false)count++;
	else in++;
	if(flag){
		if(in>=want)ans=(ans+1)%998244353;
		return;
	}
	for(long long i = 0;i < n;i++){
		if(matched[i]==false){
			f(i,count,in);
		}
	}
	matched[x]=false;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> want;
	string str;
	cin>>str;
	for(long long i = 0;i < n;i++){
		ques[i] = (str[i])=='1';
	}
	for(long long i = 0;i < n;i++)cin >> prac[i];
	for(long long i = 0;i < n;i++)f(i,0,0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
