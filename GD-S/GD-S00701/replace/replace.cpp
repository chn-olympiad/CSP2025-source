#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int n,q;
	string l1[2002];
	string l2[2002];
	string exam[2002];
	string ans[2002];
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>l1[i]>>l2[i];
	}
	for(int i=0;i<q;i++){
		int s=0;
		cin>>exam[i]>>ans[i];
		if(exam[i].length()!=ans[i].length()){
		    cout<<'0'<<endl; 
		    continue;
	    }
        for(int j=0;j<n;j++){
        	if(exam[i].find(l1[j])){
        		cout<<exam[i].find(l1[j])<<"a"<<endl;
        		if(ans[i].find(l2[j])){
        			cout<<ans[i].find(l2[j])<<"b"<<endl;
        			if(exam[i].find(l1[j])==ans[i].find(l2[j])){
        				s++;
					}
				}
			}
		}
		cout<<s<<endl;
	}

	
	return 0;
}
