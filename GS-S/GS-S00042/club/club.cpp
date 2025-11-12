#include<bits/stdc++.h>
using namespace std;
int club(){
	int n=0,h=0,v=0,w=0,q[3]={0,0,0},c=0,r=0;
	cin>>n;
	c=n/2;
	int l[n][3],s[n][3];
	for(int i=0;i<n;i++){
		h=0;
		for(int j=0;j<3;j++){
			s[i][j]=0;
			cin>>l[i][j];
			if(l[i][j]>h){
				h=l[i][j];
				v=i;
				w=j;
			}
		}
		s[v][w]=h;
		q[w]++;
	}
	h=0;
	v=0;
	w=0;
	for(int i=0;i<3;i++){
		if(q[i]>c){
			h=s[0][i];
			for(int f=0;f<q[i]-c;f++){
				for(int j=0;j<n;j++){
					if(s[j][i]>h){
						h=s[j][i];
						v=j;
						w=i;
					}
				}
				l[v][w]=0;		
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			s[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		h=0;
		for(int j=0;j<3;j++){
			if(l[i][j]>h){
				h=l[i][j];
				v=i;
				w=j;
			}
		}
		s[v][w]=h;
		r+=h;
	
	}
	return r;

	
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);	
	int t=0,n=0;
	cin>>t;
	for(int I=0;I<t;I++){

		n=club();
		cout<<n<<endl;
	}
}

