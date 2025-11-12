#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],b[105];
int c,r;
bool cmp(int x,int y){
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a + 1,a + n * m + 1,cmp);
	if(n == 1){
		for(int i = 1;i <= n * m;i ++){
		    if(b[1] == a[i]){
		    	cout << 1 << " " << i << '\n';
		    	return 0;
			}
	    }
	}else if(n == 2){
		if(b[1] == a[1]){
		    cout << 1 << " " << 1 << '\n';
		    return 0;
		}else if(b[1] == a[2]){
			cout << 1 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[3]){
			cout << 2 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[4]){
			cout << 2 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[5]){
			cout << 3 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[6]){
			cout << 3 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[7]){
			cout << 4 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[8]){
			cout << 4 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[9]){
			cout << 5 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[10]){
			cout << 5 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[11]){
			cout << 6 << " " << 2 << '\n';
		    return 0;
		}else if(b[1] == a[12]){
			cout << 6 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[13]){
			cout << 7 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[14]){
			cout << 7 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[15]){
			cout << 8 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[16]){
			cout << 8 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[17]){
			cout << 9 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[18]){
			cout << 9 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[19]){
			cout << 10 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[20]){
			cout << 10 << " " << 1 << '\n';
			return 0;
		}
	}else if(n == 3){
		if(b[1] == a[1]){
		    cout << 1 << " " << 1 << '\n';
		    return 0;
		}else if(b[1] == a[2]){
			cout << 1 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[3]){
			cout << 1 << " " << 3 << '\n';
			return 0;
		}else if(b[1] == a[4]){
			cout << 2 << " " << 3 << '\n';
			return 0;
		}else if(b[1] == a[5]){
			cout << 2 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[6]){
			cout << 2 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[7]){
			cout << 3 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[8]){
			cout << 3 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[9]){
			cout << 3 << " " << 3 << '\n';
			return 0;
		}else if(b[1] == a[10]){
			cout << 4 << " " << 3 << '\n';
			return 0;
		}else if(b[1] == a[11]){
			cout << 4 << " " << 2 << '\n';
		    return 0;
		}else if(b[1] == a[12]){
			cout << 4 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[13]){
			cout << 5 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[14]){
			cout << 5 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[15]){
			cout << 5 << " " << 3 << '\n';
			return 0;
		}else if(b[1] == a[16]){
			cout << 6 << " " << 3 << '\n';
			return 0;
		}else if(b[1] == a[17]){
			cout << 6 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[18]){
			cout << 6 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[19]){
			cout << 7 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[20]){
			cout << 7 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[21]){
			cout << 7 << " " << 3 << '\n';
			return 0;
		}else if(b[1] == a[22]){
			cout << 8 << " " << 3 << '\n';
			return 0;
		}else if(b[1] == a[23]){
			cout << 8 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[24]){
			cout << 8 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[25]){
			cout << 9 << " " << 1 << '\n';
			return 0;
		}else if(b[1] == a[26]){
			cout << 9 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[27]){
			cout << 9 << " " << 3 << '\n';
			return 0;
		}else if(b[1] == a[28]){
			cout << 10 << " " << 3 << '\n';
			return 0;
		}else if(b[1] == a[29]){
			cout << 10 << " " << 2 << '\n';
			return 0;
		}else if(b[1] == a[30]){
			cout << 10 << " " << 1 << '\n';
			return 0;
		}
	}
	return 0;
}
