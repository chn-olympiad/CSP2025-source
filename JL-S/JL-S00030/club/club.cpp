#include<bits/stdc++.h>
using namespace std;
int csp(int q,int w,int e){
	if(q>=w&&w>=e){
		return q-w;
	}
	if(q>=e&&e>=w){
		return q-e;
	}
	if(w>=e&&e>=q){
		return w-e;
	}
	if(w>=q&&q>=e){
		return w-q;
	}
	if(e>=w&&w>=q){
		return e-w;
	}
	if(e>=q&&q>=w){
		return e-q;
	}
}
int cspp(int q,int w){
	if(q>w){
		return q-w;
	}
	else{
		return w-q;
	}
}
int big(int q,int w,int e){
	if(q>=w&&q>=e){
		return q;
	}
	else if(w>=q&&w>=e){
		return w;
	}
	else if(e>=w&&e>=q){
		return e;
	}
}
int bigg(int q,int w){
	if(q>=w){
		return q;
	}
	else{
		return w;
	}
}
void bigest(int q,int w,int e){
	if(q>=w&&w>=e){
		q=0;
	}
	if(q>=e&&e>=w){
		q=0;
	}
	if(w>=e&&e>=q){
		w=0;
	}
	if(w>=q&&q>=e){
		w=0;
	}
	if(e>=w&&w>=q){
		e=0;
	}
	if(e>=q&&q>=w){
		e=0;
	}
}
void biggest(int q,int w){
	if(q>=w){
		q=0;
	}
	else{
		w=0;
	}
}
int m[99999][5],k[99999],d[99999],s[99999],f[99999];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	long long max=0,sum=0,a=0,b=0,c=0;
	for(int i=1;i<=t;i++){
		cin>>n;
		sum=0,max=0;
		for(int j=1;j<=n;j++){
			cin>>m[j][1]>>m[j][2]>>m[j][3];
			k[j]=csp(m[j][1],m[j][2],m[j][3]);
		}
		for(int j=1;j<=n;j++){
			if(k[j]>=max){
				max=k[j];
				d[j]++;
			}
		}
		for(int j=n;j>=1;j--){
			if(a>n/2||b>n/2||c>n/2){
				break;
			}
			if(d[j]==1){
				sum=sum+big(m[j][1],m[j][2],m[j][3]);
				bigest(m[j][1],m[j][2],m[j][3]);
				if(m[j][3]==0){
					c++;
				}
				else if(m[j][1]==0){
					a++;
				}
				else{
					b++;
				}
				d[j]=3;
			}
		}
		max=0;
		if(a==n/2){
			for(int j=1;j<=n;j++){
				if(d[j]==3){
					s[j]=cspp(m[j][2],m[j][3]);
				}
			}
			for(int j=1;j<=n;j++){
				if(s[j]>=max){
					max=s[j];
					f[j]++;
				}
			}
			for(int j=n;j>=1;j--){
				if(b>n/2||c>n/2){
					break;
				}
				if(f[j]==1){
					sum=sum+bigg(m[j][2],m[j][3]);
					biggest(m[j][2],m[j][3]);
					if(m[j][3]==0){
						c++;
					}
					else{
						b++;
					}
					f[j]=5;
				}
			}
		}
		cout<<sum;
	}
	
	return 0;
}
