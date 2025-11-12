#include<bits/stdc++.h>
using namespace std;
string str;
int a[1200010];
bool cmp(int t,int e){
	if(t>e)return 1;
	return 0;
	}
int main(){
	ios::sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int cnt=0,chang=str.size();
	for(int i=0;i<chang;i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[cnt]=str[i]-'0';
			cnt++;
			}
		}
		sort(a,a+cnt,cmp);
		for(int i=0;i<cnt;i++){
			cout<<a[i];
			}
	return 0;
}
