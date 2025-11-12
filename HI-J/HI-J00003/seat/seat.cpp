#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int R = a[1];
	sort(a  + 1,a + 1 + n * m);
	int geshu = 0;
	for(int i = 1;i <= n * m;i++){
		if(a[i] == R){
			geshu =n * m - i + 1;
			break;
		}
	}
	if(geshu == 1){
		cout << 1 << " " << 1;
		return 0;
	}
	int h = 1,j = 0,f = 1;
    for(int i = 1;i <= geshu;i++){
	    
	  	if(f == 1){
		  j++;
	  		if(j > n){
    		f = 0;
    		j=n;
    		h++;
		    }
		}
		else{
		j--;
		if(j < 1){
			f = 1;
			j = 1;
			h++;
		}	
		}
	}
	cout << h << " " << j;
	return 0;
	fclose(stdin);
	fclose(stdout);
	
} 
