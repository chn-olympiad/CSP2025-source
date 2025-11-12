#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	string s;
	cin>>s;
	int v[s.size()+5];
	//vector<int> v;
	int len=s.size();
	for(int i=0;i<=len-1;i++){
		char c=s[i];
		if(c>='0' and c<='9'){
			int num=c-'0';
			v[cnt]=num;
			cnt++;
		}
	}
	sort(v,v+cnt,cmp);
	for(int i=0;i<=cnt-1;i++){
		cout<<v[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
