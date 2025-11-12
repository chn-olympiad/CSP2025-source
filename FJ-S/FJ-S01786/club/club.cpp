#include<iostream>
#include<queue>
using namespace std;
long long t,n,lenx = 0,leny = 0,lenz = 0,i,sum = 0;
long long a[1000005][3],x[1000005],y[1000005],z[1000005];
int main(){
	freopen("club.in","r",stdin);
	cin>>t;
	while(t--){
		lenx = 0;
		leny = 0;
		lenz = 0;
		i = -1;
		sum = 0;
		cin>>n;
		for(int c = 0;c < n;c++){
			cin>>a[c][0]>>a[c][1]>>a[c][2];
			if((a[c][0] >= a[c][1])&&(a[c][0] >= a[c][2])){
				x[lenx] = c;
				lenx++;
			}
			else if(a[c][1] >= a[c][2]){
				y[leny] = c;
				leny++;
			}
			else{
				z[lenz] = c;
				lenz++;
			}
		}
		//x
		for(int c = 0;c = lenx-1;c--){
			for(int c1 = c;c1 < lenx-1;c1++){
				if(a[x[c1]][0] < a[x[c1+1]][0]){
					i = x[c1];
					x[c1] = x[c1+1];
					x[c1+1] = i;
				}
			}
		}
		if(lenx > n/2){
			/*for(int c = 0;c = lenx-1;c--){
				for(int c1 = c;c1 > 0;c1++){
					if((a[x[c1]][1] > a[x[c1-1]][1])||((a[x[c1]][1] == a[x[c1-1]][1])&&(a[x[c1]][0] < a[x[c1-1]][0]))){
						i = x[c1];
						x[c1] = x[c1-1];
						x[c1-1] = i;
					}
				}
			}*/
			while(lenx > n/2){
				if(leny >= n/2){
					z[lenz] = x[lenx-1];
					lenx--;
					lenz++;
				}
				else if(lenz >= n/2){
					y[leny] = x[lenx-1];
					lenx--;
					leny++;
				}
				else if(a[x[lenx-1]][1] > a[x[lenx-1]][2]){
					y[leny] = x[lenx-1];
					lenx--;
					leny++;
				}
				else if(a[x[lenx-1]][1] < a[x[lenx-1]][2]){
					z[lenz] = x[lenx-1];
					lenx--;
					lenz++;
				}
				else{
					if(leny > lenz){
						z[lenz] = x[lenx-1];
						lenx--;
						lenz++;
					}
					else{
						y[leny] = x[lenx-1];
						lenx--;
						leny++;
					}
				}
			}
		}
		//y
		for(int c = 0;c = leny-1;c--){
			for(int c1 = c;c1 < leny-1;c1++){
				if(a[y[c1]][0] < a[y[c1+1]][0]){
					i = y[c1];
					y[c1] = y[c1+1];
					y[c1+1] = i;
				}
			}
		}
		if(leny > n/2){
			while(leny > n/2){
				if(lenx >= n/2){
					z[lenz] = y[leny-1];
					leny--;
					lenz++;
				}
				else if(lenz >= n/2){
					x[lenx] = y[leny-1];
					leny--;
					lenx++;
				}
				else if(a[y[leny-1]][1] > a[y[leny-1]][3]){
					x[lenx] = y[leny-1];
					leny--;
					lenx++;
				}
				else if(a[y[leny-1]][1] < a[y[leny-1]][3]){
					z[lenz] = y[leny-1];
					leny--;
					lenz++;
				}
				else{
					if(lenx > lenz){
						z[lenz] = y[leny-1];
						leny--;
						lenz++;
					}
					else{
						x[lenx] = y[leny-1];
						leny--;
						lenx++;
					}
				}
			}
		}
		//z
		//cout<<"z";
		for(int c = 0;c = lenz-1;c--){
			for(int c1 = c;c1 < lenz-1;c1++){
				if(a[z[c1]][0] < a[z[c1+1]][0]){
					i = z[c1];
					z[c1] = z[c1+1];
					z[c1+1] = i;
				}
			}
		}
		if(lenz > n/2){
			while(lenz > n/2){
				if(lenx >= n/2){
					y[leny] = z[lenz-1];
					lenz--;
					leny++;
				}
				else if(leny >= n/2){
					x[lenx] = z[lenz-1];
					lenz--;
					lenx++;
				}
				else if(a[z[lenz-1]][1] > a[y[lenz-1]][2]){
					x[lenx] = z[lenz-1];
					lenz--;
					lenx++;
				}
				else if(a[z[lenz-1]][1] < a[z[lenz-1]][2]){
					y[leny] = z[lenz-1];
					lenz--;
					leny++;
				}
				else{
					if(lenx > leny){
						y[leny] = z[lenz-1];
						lenz--;
						leny++;
					}
					else{
						x[lenx] = z[lenz-1];
						lenz--;
						lenx++;
					}
				}
			}
		}
		//sum
		for(int c = 0;c < lenx;c++){
			sum += a[x[c]][0];
		}
		for(int c = 0;c < leny;c++){
			sum += a[y[c]][1];
		}
		for(int c = 0;c < lenz;c++){
			sum += a[z[c]][2];
		}
		cout<<sum;
	}
	freopen("club.text","w",stdout);
return(0);
}

