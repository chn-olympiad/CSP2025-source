#include<bits/stdc++.h>
using namespace std;
int Value[1000001];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len = s.length(),cnt = 0,temp = 0;
	int t = 0;
	for (int i = 0;i < len;i++){
		if (s[i] >= '0' && s[i] <= '9'){
			temp = int(s[i] - '0');
			//cout<<"   "<<temp<<" \n";
			Value[cnt++] = temp;
			sort(Value,Value + cnt,cmp);
			/*for (int x = 0;x < cnt;x++){
				cout<<x<<" ";
			}*/
		}
		else {
			s[i] == ' ';
		}
	}
	for (int i = 0;i < cnt;i++){
		cout<<Value[i];
	}
	return 0;
}