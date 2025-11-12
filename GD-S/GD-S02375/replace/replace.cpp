#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s;
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cin>>s;
		}
	}
	string s1;
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
			cin>>s1;
		}
	}
	int a=0;
	while(q){
		a=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<2;j++){
				if(s==s1){
					a++;
				}
			}
		}
		cout<<a<<"\n";
		a=0;
		q--;
		for(int i=0;i<q;i++){
			for(int j=0;j<2;j++){
				if(s1==s){
					a++;
				}
			}
		}
		cout<<a<<"\n";
		a=0;
		q--;
		for(int i=0;i<2;i++){
			for(int j=0;j<n;j++){
				if(s==s1){
					a++;
				}
			}
		}
		cout<<a<<"\n";
		a=0;
		q--;
		for(int i=0;i<2;i++){
			for(int j=0;j<q;j++){
				if(s1==s){
					a++;
				}
			}
		}
		cout<<a<<"\n";
		a=0;
		q--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
