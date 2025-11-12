#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int id = 0;
	int si = s.size();
	 
	for(int i = 0;i < si;i++){
		if(s[i] >= '0' and s[i] <= '9'){
			id++;
			a[id] = s[i] - '0';
		}
	}
	sort(a + 1,a + id + 1,cmp);
	for(int i = 1;i <= id;i++){
		cout<<a[i];
	}
	 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
