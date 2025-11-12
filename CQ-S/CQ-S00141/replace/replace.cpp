#include <bits/stdc++.h>
using namespace std;
string a[200005],b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q){
		string w,d;
		int num=0;
		cin>>w>>d;
		for(int i=1;i<=n;i++){
			if(w.find(a[i])<5000005){
				if(d.find(b[i])<5000005){
					string l=w;
					long long wew=l.find(a[i]),wed=d.find(b[i]);
					while(wew<5000005){

						
						int flg=0;
						while(wew!=wed){

							if(l.find(a[i])>5000005){
		
								flg=1;
								break;
							}
							l[wew]=' ';
							

							wew=l.find(a[i]);
						}
						
						if(flg) break;
						string ll=w;
						for(int j=0;a[i][j]<='z'&&a[i][j]>='a';j++){
							ll[wew+j]=b[i][j];

						}
						if(ll==d){
							num++;
						}
						l[wew]=' ';
						wew=l.find(a[i]);
					}
				}
			}

		}
		cout<<num<<endl;
		q--;
	}
	return 0;
} 
