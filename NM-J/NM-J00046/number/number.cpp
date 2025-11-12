#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string x;
	cin>>x;
	vector<long long >vec;
	for(int i=0;i<x.size();i++){
		if(x[i]>='1'&&x[i]<='9'||x[i]=='0'){
			long long t=0;
			t=x[i]-'0';
			vec.push_back(t) ;
		}
	}
	
		for(int i=0;i<vec.size();i++){
			int k=i;
			for(int j=0;j<vec.size();j++){
				if(vec[k]<vec[j]&&j>k){
					int t=0;
					t=vec[k];
					vec[k]=vec[j];
					vec[j]=t;
					k=j;
				}
				if(vec[k]>vec[j]&&j<k){
					int t=0;
					t=vec[k];
					vec[k]=vec[j];
					vec[j]=t;
					k=j;
				}
			}
			
		}
		
	for(int i=0;i<vec.size() ;i++){
		cout<<vec[i];
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;

}
