#include<bits/stdc++.h>
using namespace std;
string s;
int num[10];
bool tof=false;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]){
			if(i!=0) tof=true;
			if(i==0&&tof==false){
				cout<<0;
				break;
			}
			cout<<i;
			num[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

