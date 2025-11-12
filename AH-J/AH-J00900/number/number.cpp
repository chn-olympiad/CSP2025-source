#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[100005];
bool cmp(int x,int y){
	if(x>y) return 1;
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int p=s.size();
	int num=0;
	for(int i=0;i<p;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-48;
			num++;
		}
	}
	sort(a+0,a+num+1,cmp);
	for(int i=0;i<num;i++){
		cout<<a[i];
	}
    return 0;
    fclose(stdin);
    fclose(stdout);
}
