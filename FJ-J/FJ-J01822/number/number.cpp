#include<bits/stdc++.h>
using namespace std;
int a[1000010],ss,sss = 1;
string s;
bool cmp(int aa,int bb){
	return aa > bb;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ss = s.size();
	for(int i = 0;i < ss;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[sss] = int(s[i] - '0');
			//cout<<a[sss]<<" ";
			sss++; 
		}
		//cout<<s[i]<<endl;
	}
	sort(a + 1,a + sss + 1,cmp);
	for(int i = 1;i <= sss;i++){
		cout<<a[i];
	}
	return 0;
} 
