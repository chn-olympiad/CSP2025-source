#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,ui[10000],vi[10000],wi[10000],k,cj[10000],aji[10000][10000],cost,b = 0,z,a[1000];
    cin >> n >> m >> k;
    for (int i = 0;i < m;i ++){
		cin >> ui[i] >> vi[i] >> wi[i];
	}
	for (int j = 0;j < k;j ++){
		cin >> cj[j];
		for (int i = 0;i < n;i ++){
			cin >> a[j][i];
		}
	}

	for (int i = 0;i < m;i ++){
		if(wi[b] > wi[i]){
			b++;
			i = 0;
		}
	}

    a[1] = b;
    b = 0;
    if(n == 2){
		cout << wi[a];
		return 0;
    }

	for (int i = 0;i < m;i ++){
		if(i == a[1]){
			i ++;
		}
		if(b == a[1]){
			b ++;
		}
		if(wi[b] > wi[i]){
			b++;
			i = 0;
		}
	}
	a[2] = b;
	b = 0;
	
	if(n == 3){
	
	}
    return 0;
}


