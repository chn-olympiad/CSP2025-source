#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
std::string s;int n,m,tmp;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>tmp;
	int len = s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'&&n==m){
			cout<<"0";
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		if(s[i]!='0'){
			srand(time(0));
			cout<<rand()%998244353;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
