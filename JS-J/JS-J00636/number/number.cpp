#include<bits/stdc++.h>
using namespace std;
string s;
int a[1001145],j;
int main(){
    //114
    //MC & ETO & PVZRH
    //wo yao shang mi huo xing wei !
    //sto chen_zhe orz
    //sto kkksc03 orz
    //I love CCF more than I love yxy!
    //RP++
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
	    if(s[i]>='0' && s[i]<='9'){
            a[j]=s[i]-'0';
            j++;
	    }
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
        cout<<a[i];
	}
	return 0;
}
