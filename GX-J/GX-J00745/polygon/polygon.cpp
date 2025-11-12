//#include <bits/stdc++.h>
//using namespace std;
//int sumof(vector<int>& vec){
	//int sum=0;
	//for(int i=0;i<vec.size();i++){
		//sum+=vec[i];
	//}
	//return sum;
//}
//int maxof(vector<int>& vec){
	//int maxn=vec[0];
	//for(int i=1;i<vec.size();i++){
		//if(vec[i]>maxn) maxn=vec[i];
	//}
	//return maxn;
//}
//bool can(vector<int>& vec){
	//int sum=sumof(vec);
	//int maxn=maxof(vec);
	//if(sum>2*maxn) return true;
	//else return false;
//}
//int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	//int n;
	//cin>>n;
	//int sum=0;
	//vector<int> vec(n);
	//for(int i=0;i<n;i++) cin>>vec[i];
	//for(int i=3;i<=n;i++){
		//for(int j=0;j<=n-i;j++){
			//vector<int> c;
			//for(int k=j;k<=j+i;k++){
				//c.push_back(vec[k]);
			//}
			//if(can(c)) sum++;
		//}
	//}
	//cout<<sum;
//}

#include <bits/stdc++.h>
using namespace std;
int sumof(vector<int>& vec){
	int sum=0;
	for(int i=0;i<vec.size();i++){
		sum+=vec[i];
	}
	return sum;
}
int maxof(vector<int>& vec){
	int maxn=vec[0];
	for(int i=1;i<vec.size();i++){
		if(vec[i]>maxn) maxn=vec[i];
	}
	return maxn;
}
bool can(vector<int>& vec){
	int sum=sumof(vec);
	int maxn=maxof(vec);
	if(sum>2) return true;
	else return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	vector<int> vec(n);
	for(int i=0;i<n;i++) cin>>vec[i];
	for(int i=3;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			vector<int> c;
			for(int k=j;k<=j+i;k++){
				c.push_back(vec[k]);
			}
			if(can(c)) sum++;
		}
	}
	cout<<sum;
}
