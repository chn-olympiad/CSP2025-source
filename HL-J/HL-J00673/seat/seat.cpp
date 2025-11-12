#include <bits/stdc++.h>
using namespace std;
struct data{
	int score;
};
bool cmp(data x,data y){
	if(x.score>y.score){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mn=n*m;
	data a[mn];
	for(int i=0;i<mn;i++){
		cin>>a[i].score;
	}
	int ans=a[0].score;//小R的成绩 
	sort(a,a+mn,cmp);
	int num=0;//小R的排名 
	for(int i=0;i<mn;i++){
		if(a[i].score==ans){
			num=i+1;
			break;
		}
	}
	if(num<=n){
		cout<<1<<' '<<num;
		return 0;
	}
	int hang=0,lie=0;
	lie=(num+n-1)/n;
	if(lie%2==1){
		int q=(lie-1)*n;
		hang=num%q;
	}else{
		int q=(lie-1)*n;
		hang=n-(num%q)+1;
	}
	cout<<lie<<' '<<hang;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
