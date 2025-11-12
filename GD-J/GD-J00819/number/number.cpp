#include <bits/stdc++.h>
using namespace std;
/*
The club isnt best place to find the lover so the bar is where i go~~
                                                                    --------Shape of you
qiu qiu le CCF bie gua wo fen rang wo zhe ge jv ruo neng na yi ci 1=,zui hou yi chang csp-j le,hai you yi chang csp-s jiu yao AFO le:(
                                                                                                                                      ------From _Arinexis_
*/
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;cin>>s;
    string di;
    for(char c:s){
    	if(isdigit(c)){
    		di+=c;
		}
	}
	sort(di.begin(),di.end());
	reverse(di.begin(),di.end());
	cout<<di;
    return 0;
}
//#Shang4Shan3Ruo6Shui4
