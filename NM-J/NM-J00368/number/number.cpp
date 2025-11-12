#include<bits/stdc++.h>
using namespace std;
string ss;
char aa[1000006];long long jj=1;

bool cmp(char xx,char yy){
	return xx>yy;
}
bool f=false;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>ss;
	for(int i=0;i<=ss.size()-1;i++){
		if(ss[i]>='0'&&ss[i]<='9'){
            aa[jj]=ss[i];
			if(aa[jj]>'0'){
				f=true;
			}
			jj++;
		}
	}
	if(f==false){
		cout<<0;
		return 0;
	}
	sort(aa+1,aa+jj+1,cmp);
	for(int ii=1;ii<=jj;ii++){
	    cout<<aa[ii];
	}
	return 0;
}
