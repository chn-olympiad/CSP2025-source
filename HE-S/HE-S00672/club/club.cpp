#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int z,f,a,b,c,q=0,w=0,e=0,h=0;
		cin>>z;
		while(z--){
		
		
			cin>>a>>b>>c;
			if(a<b){
				if(b<c){
					if(q<z/2){
						h+=c;
						q++;
					}else if(w<z/2){
						h+=b;
						w++;
					}else{
						h+=a;
						e++;
					}
				}else{
					if(e<z/2){
						h+=b;
						w++;
					}else if(a<c){
						if(q<z/2){
							h+=c;
							q++;
						}else{
							h+=a;
							e++;
						}
					}else if(e<z/2){
						h+=a;
						e++;
					}else{
						h+=c;
						q++;
					}
					
				}
			}else if(a<c){
				if(q<z/2){
					h+=c;
					q++;
				}else if(e<z/2){
					h+=a;
					e++;
				}else{
					h+=b;
					b++;
				}
			}else if(e<z/2){
					h+=a;
					e++;
			}else if(b<c){
				if(q<z/2){
					h+=c;
					q++;
				}else{
					h+=b;
					b++;
				}
			}else if(q<z/2){
				h+=c;
				q++;
			}else{
				h+=b;
				w++;
			}
		}
		
		cout<<h<<endl;
	}
	

	return 0;
	fclose(stdin);
	fclose(stdout);
}
