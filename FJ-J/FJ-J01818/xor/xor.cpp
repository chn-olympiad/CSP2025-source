#include<bits/stdc++.h>

using namespace std;

struct date{
	int h , t;
}b[50000000];

int n , k;
int a[1000000];
int l , ans;

bool cmp(date x , date y){
	if(x.h > y.h){
		return false;
	}else if(x.h < y.h){
		return true;
	}else{
		return x.t < y.t;
	}
}

int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout); 
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
            int sum = a[i];
			for(int k = i + 1;k <= j;k++){
			    sum = (sum xor a[j]);
		    }
		    if(sum == k){
		    	b[l + 1].h = i;
		    	b[l + 1].t = j;
				l++;
			}
		}
	}
	sort(b + 1 , b + l + 1 , cmp);
	int p = 1;
	for(int i = 1;i <= l;i++){
		if(b[i].h >= p){
		    ans++;
		    p = b[i].t + 1;
		}
	}
	cout << ans <<endl;
	
	return 0;
}
