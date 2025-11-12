#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	
	string a;
	cin>>a;
//	cout<<"\n";
//	cout<<a<<"\n";
	vector<long long> vec;
	
	for(long long i=0;i<a.length();i++){
		
		char t=a[i];
		if(t>='0' && t<='9'){
			vec.push_back(t-'0');
			
		}
		
	}
	
//	for(int i=0;i<vec.size();i++){
//		
//		cout<<vec[i]<<" ";
//		
//	}
	
	for(long long i=0;i<vec.size();i++){
		for(long long j=1;j<vec.size()-i;j++){
			
			if(vec[j-1]<vec[j]){
				
				long long t=vec[j];
				vec[j]=vec[j-1];
				vec[j-1]=t;
				
			}
			
		}
		
		
	}
	if(vec[0]!=0){
		for(long long i=0;i<vec.size();i++){
		
			cout<<vec[i];
		
		}
	}else{
		cout<<"0";
	}
	return 0;
	
}
