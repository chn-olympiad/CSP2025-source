#include <bits/stdc++.h>
using namespace std;
struct data{
	char x;
};
bool cmp(data b,data c){
	if(b.x-'0'>c.x-'0'){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	int num=s.size();
	data a[num];
	int cnt=0;
	for(int i=0;i<num;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j++].x=s[i];
			cnt++;
		}
	}
	 sort(a,a+cnt,cmp);
	 for(int i=0;i<cnt;i++){
	 	cout<<a[i].x;
	 }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
