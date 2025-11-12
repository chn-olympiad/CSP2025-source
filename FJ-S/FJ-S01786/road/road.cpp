#include<iostream>
using namespace std;
long long n,m,k;
long long v[15],u[1100010][3];
bool road[10110][10110],vd[15] = {false},ud[1100010] = {false},a[10110] = {false}; 
void re(){
	for(long long c = 1;c <= n+k;c++){
		for(long long c1 = 1;c1 <= n+k;c1++){
			road[c][c1] = false;
		}
	}
	for(long long c = 1;c <= n+k;c++){
		a[c] = false;
	}
	for(long long c = 1;c <= k;c++){
		vd[c] = false;
	}
	return;
}
long long check(){
	bool flag = true;
	while(flag){
		flag = false;
		for(long long c = 1;c <= n+k;c++){
			if(!a[c]){
				for(long long c1 = 1;c1 <= n+k;c1++){
					if(road[c][c1]&&a[c1]){
						a[c] = true;
						flag = true;
					}
				}
			}
		}
	}
	long long sum = 0;
	for(long long c = 1;c <= n;c++){
		if(a[c]){
			sum++;
		}
	}
	return(sum);
}
int main(){
	long long i,min;
	freopen("road.in","r",stdin);
	cin>>n>>m>>k;
	for(long long c = 1;c <= m;c++){
		cin>>u[c][0]>>u[c][1]>>u[c][2];
		min += u[c][2];
	}
	for(long long c = 1;c <= k;c++){
		for(long long c1 = 0;c1 <= n;c1++){
			cin>>i;
			if(c1 != 0){
				u[m+n*(c-1)+c1][0] = n+c;
				u[m+n*(c-1)+c1][1] = c1;
				u[m+n*(c-1)+c1][2] = i;
				min += i;
			}
			else{
				v[c] = i;
			}
		}
	}
	while(!ud[m+n*k+1]){
		re();
		if(ud[1]){
			i = 1;
			for(long long c = 1;ud[c];c++){
				i = c;
				ud[c] = false;
			}
			ud[i+1] = true;
		}
		else{
			ud[1] = true;
		}
		if(ud[m+n*k+1]){
			break;
		}
		i = 0;
		for(long long c = m+1;c <= m+n*k;c++){
			if(ud[c]){
				vd[(c-m)/n+1] = true;
				c = ((c-m)/n+1)*n+m+1;
			}
		}
		for(long long c = 1;c <= m+n*k;c++){
			if(ud[c]){
				road[u[c][0]][u[c][1]] = true;
				road[u[c][1]][u[c][0]] = true;
				i += u[c][2];
			}
		}
		for(long long c = 1;c <= k;c++){
			if(vd[c]){
				i += v[c];
			}
		}
		if(check() == n){
			if(i < min){/*
				for(long long c = 1;c <= n+k;c++){
					for(long long c1 = 1;c1 <= n+k;c1++){
						cout<<(road[c][c1]?1:0);
					}
					cout<<endl;
				}
				cout<<i<<endl;*/
				min = i;
			}
		}
	}
	cout<<min;
	freopen("road.out","w",stdout);
return(0);
}

