#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int a,x,sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for (int i=0;i<a;i++){
		cin>>x;
		sum+=x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	a--;
	while (v[a]*2>=sum){
		sum-=v[a];
		a--;
	}
	a++;
	if (a<3){
		cout<<0;
		return 0;
	}
	if (a==3){
		if (v[0]+v[1]>v[2]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	cout<<pow(a-2,2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
