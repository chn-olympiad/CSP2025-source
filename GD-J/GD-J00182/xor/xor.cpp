#include<vector>
#include<iostream>
using namespace std;
int a[500005],n,k;
bool check(vector<int> points,int x,int point){
	if(x>point){
		if(points.size()&1) return 0;
		for(int i=1;i<points.size();i+=2) if(a[points[i]]^a[points[i-1]]!=k) return 0;
		return 1;
	}
	if(check(points,x+1,point)) return 1;
	else{
		points.push_back(x);
		if(check(points,x+1,point)) return 1;
		else return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	int l=0,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check({},1,mid*2)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
