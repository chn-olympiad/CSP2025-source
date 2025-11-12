#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct p{
	int a[3];
	int b = 0;
	bool f = 0;
};
bool cmp(p*, p*);
bool cmp1(p*, p*);
bool cmp2(p*, p*);
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	
	cin>>t;
	for (int i = 0; i < t; i++)
	{
		int n, ans=0;
		p l[100005];
		p* lp[3][100005];
		cin>>n;
		for (int i = 0; i < n; i++)
		{
			for(int j = 0 ; j < 3; j++){
				cin>>l[i].a[j];
				lp[j][i] = &l[i];
				if(l[i].a[j] > l[i].b){
					l[i].b = l[i].a[j];
				}
			}
		}
		
		
		sort(lp[0], lp[0] + n, cmp);
		sort(lp[1], lp[1] + n, cmp1);
		sort(lp[2], lp[2] + n, cmp2);
		//cout<<lp[0][1] -> a[0]<<endl<<endl;
		for (int i = 0; i < 3; i++)
		{
			int rem = n / 2;
			for(int j = 0 ; j < n ; j++){
				if(rem){
					if(lp[i][j] -> b == lp[i][j] -> a[i] && !lp[i][j] -> f){
						ans += lp[i][j] -> b;
						//cout<<lp[i][j] -> b<<endl<<endl;
						lp[i][j] -> f = 1;
						rem --;
					}
				}else{
					break;
				}
			}
		}
		
		cout<<ans<<endl;
	}
	
	
	return 0;
}

bool cmp(p* a, p* b){
	if(a -> a[0] == b -> a[0])
		return a -> b > b -> b;
	return a -> a[0] > b -> a[0];
}
bool cmp1(p* a, p* b){
	if(a -> a[1] == b -> a[1])
		return a -> b > b -> b;
	return a -> a[1] > b -> a[1];}
bool cmp2(p* a, p* b){
	if(a -> a[2] == b -> a[2])
		return a -> b > b -> b;
	return a -> a[2] > b -> a[2];
}
