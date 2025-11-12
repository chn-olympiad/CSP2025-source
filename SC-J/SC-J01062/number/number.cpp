include<bits/stdc++.h>
using namespace std;
int cnt[10]={0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			cnt[a[i]-'0']++;
		}
	}
	int flag=0;
	for(int i=1;i<=9;i++){
		if(cnt[i]!=0)flag=1;
	}
	if(flag==0){
		cout<<'0';
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	return 0;
}