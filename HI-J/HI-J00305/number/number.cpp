#include <bits/stdc++.h>
using namespace std;
string s;
int vis[1000010],tot=1; 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			vis[tot]=s[i]-'0';
			tot++;
		}
	}
	tot--;
	sort(vis+1,vis+tot+1,cmp);
	for(int i=1;i<=tot;i++) cout<<vis[i];
    return 0;
}
//8:31 i will start my contest now
//orz ccf pinkrabbit xht kkksc03
//let me have 1st!(in HI)
//give me power!!!
//now i will read t1234 first
//my log start in 8:46
//this is a good T1
//thinking......
//now is 8:46 i will code it
//8:49 code end
//8:49 not pass small cases
//8:51 pass small cases
//8:58 pass big cases
//8:58 make homemade cases
//8:59 pass homemade cases
//9:00 end T1!!!!!!!!!!!!!
//check at 11:07 no problem

