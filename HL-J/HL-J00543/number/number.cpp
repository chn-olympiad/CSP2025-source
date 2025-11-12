#include<bits/stdc++.h>
using namespace std;
int a[1000020];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	int ps,p=0,ze=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		ps=int (s[i]);
		if(ps<70){
			if(ps==48){
				ze++;
			}
			else{
			a[p]=ps-48;
			p++;
			}
		}
	}
	sort(a,a+p);
	for(int i=p;i>=0;i--){
		if(a[i] !=0){
		cout<<a[i];
		}
	}
	for(int i=1;i<=ze;i++){
		cout<<0;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
