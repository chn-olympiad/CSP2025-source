#include<bits/stdc++.h> 
using namespace std;
struct student{
	int a,b,c;
	int diff;
};
int n,t;
vector<student> a;

bool cmp(student x,student y){
	return x.diff>y.diff;
}

long long cmput(vector<student> &a){
	for(int i=0;i<n;i++){
		a[i].diff=a[i].a-a[i].b;
	}sort(a.begin(),a.end(),cmp);
	long long sum=0;
	for(int i=0;i<n/2;i++){
		sum+=a[i].a;
	}
	for(int i=n/2;i<n;i++){
		sum+=a[i].b;
	}return sum;
}
int main(){
	freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		vector<student> a(n);
		for(int j=0;j<n;j++){
			student &k=a[j];k.diff=0;
			cin>>k.a>>k.b>>k.c;
		}
		cout<<cmput(a)<<endl;
		a.clear();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

