#include<bits/stdc++.h>
using namespace std;
int sum[555555];
int n,t[100010],a[555555],b[555555],c[555555];
int a1[555555],b1[555555],c1[555555];
int s[3000000],d[3000000];
int e[5555555],w[5555555];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	int num=0;
	for(int i=0;i<n;i++){
		cin>>t[i];
		int m=0;
		for(int j=num;j<t[i]+num;j++){
			cin>>a[j]>>b[j]>>c[j];
			s[j*3]=a[j];
			s[j*3+1]=b[j];
			s[j*3+2]=c[j];
			d[j*3]=0;
			d[j*3+1]=1;
			d[j*3+2]=2;
			m++;
		}
		num+=m;
	}
	for(int i=0;i<num*3;i+=3){
		for(int j=i;j<i+3;j++){
			for(int k=i;k<i+3;k++){
				if(s[j]>s[k]){
					swap(s[j],s[k]);
					swap(d[j],d[k]);
				}
			}
		}
	}
	num=0;
	int q=0;
	for(int i=0;i<n;i++){
		int m=0;
		for(int j=num;j<t[i]+num;j++){
			if(d[j*3]==0){
				a1[i]++;
			}else if(d[j*3]==1){
				b1[i]++;
			}else{
				c1[i]++;
			}
			m++;
		}
		if(a1[i]>t[i]/2){
			
			for(int j=num*3;j<t[i]*3+num*3;j+=3){
				e[q]=s[j]-s[j+1];
				w[q]=q;
				q++;
			}
			for(int j=num*3;j<t[i]*3+num*3;j+=3){
				for(int k=num*3;k<t[i]*3+num*3;k+=3){
					if(e[j/3]<e[k/3]){
						swap(e[j/3],e[k/3]);
						swap(w[j/3],w[k/3]);
					}
				}
				
			}
			swap(s[w[q-1]*3],s[w[q-1]*3+1]);
			swap(d[w[q-1]*3],d[w[q-1]*3+1]);
			a1[i]--;
			b1[i]++;
		}
		if(b1[i]>t[i]/2){
			
			for(int j=num*3+1;j<t[i]*3+num*3+1;j+=3){
				e[q]=s[j]-s[j+1];
				w[q]=q;
				q++;
			}
			for(int j=num*3+1;j<t[i]*3+num*3+1;j+=3){
				for(int k=num*3+1;k<t[i]*3+num*3+1;k+=3){
					if(e[j/3]<e[k/3]){
						swap(e[j/3],e[k/3]);
						swap(w[j/3],w[k/3]);
					}
				}
				
			}
			swap(s[w[q-1]*3+1],s[w[q-1]*3+2]);
			swap(d[w[q-1]*3+1],d[w[q-1]*3+2]);
			b1[i]--;
			c1[i]++;
		}
		if(c1[i]>t[i]/2){
		
			for(int j=num*3+2;j<t[i]*3+num*3+2;j+=3){
				e[q]=s[j]-s[j-2];
				w[q]=q;
				q++;
			}
			for(int j=num*3+2;j<t[i]*3+num*3+2;j+=3){
				for(int k=num*3+2;k<t[i]*3+num*3+2;k+=3){
					if(e[j/3]<e[k/3]){
						swap(e[j/3],e[k/3]);
						swap(w[j/3],w[k/3]);
					}
				}
				
			}
			swap(s[w[q-1]*3+2],s[w[q-1]*3]);
			swap(d[w[q-1]*3+2],d[w[q-1]*3]);
			c1[i]--;
			a1[i]++;
		}
		num+=m;
		
	}
	num=0;
	for(int i=0;i<n;i++){
		int m=0;
		for(int j=num;j<t[i]+num;j++){
			sum[i]+=s[j*3];
			m++;
		}
		num+=m;
	}
	for(int i=0;i<n;i++){
		cout<<sum[i]<<endl;
	}
	return 0;
}

/*   cs CCF你出这么难的题想干嘛啊
	我直接就是化身少羽******
	啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
	
	
	虽然说我第一题做不出来，但没事，因为
	 
	
	
	3
	4
	4 2 1
	3 2 4
	5 3 4
	3 5 1
	4
	0 1 0
	0 1 0
	0 2 0
	0 2 0
	2 
	10 9 8
	4 0 0
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	我其他题也做不出来啊喂 ！！！！！ 
*/ 
