#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int m=s.size();
//	vector<int>a(m);
	//int cnt=0;
	int tong[15]={};
//	cout<<s.size()<<'\n';
	for(int i=0;i<m;i++){
		if(s[i]>='0'&&s[i]<='9'){
			tong[s[i]-'0']++;
//			cout<<a[cnt]<<' ';
		}
	}
//	sort(a,a+cnt);

	for(int i=9;i>=0;i--){
		if(tong[i]!=0){
			for(int j=0;j<tong[i];j++){
				printf("%d",i);
			}
		}
//		printf("%d",tong[i]);
	}
	return 0;
}
