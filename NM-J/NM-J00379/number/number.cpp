#include <iostream>
#include <vector>
using namespace std;
bool fun(long long a,long long b){
	return a>=b;
};
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	string a;
	cin>>a;
	vector<long long>vec;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			int dd=a[i]-'0';
			vec.push_back(dd);
			
		}
	}
	for(int i=0;i<vec.size();i++){
	//	cout<<vec[i];
	}
//	sort(vec.begin(),vec.end(),fun);
//	for(int i=0;i<vec.size()-2;i++){
//		fun(vec[i],vec[i+1]);
//	}	
	for(int j=0;j<vec.size();j++){
			for(int i=0;i<vec.size()-1;i++){
		if(vec[i]<vec[i+1]){
			int a=vec[i];
			vec[i]=vec[i+1];
			vec[i+1]=a;
		}
	}
	}

//	cout<<"\n";
	for(int i=0;i<vec.size();i++){
		cout<<vec[i];
	}
	return 0;
}
