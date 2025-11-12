#include<bits/stdc++.h>
using namespace std;
struct sum{
	int one,two,three;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a=0,b=0,d=0,ans[6],l=0;
	sum c[100005];
	cin >> a;
	for(int i=0;i < a;i++){
		cin >> b;
		int e=0,f=0,g=0,h=b/2,k=0;
		for(int j=0;j < b;j++){
			cin >> c[j].one >> c[j].two >> c[j].three;
		}
		for(int j=0;j < b;j++){
            if(c[j].one>c[j].two && c[j].one>c[j].three){
                e++;
                k=k+c[j].one;
            }else if(c[j].two>c[j].one && c[j].two>c[j].three){
                f++;
                k=k+c[j].two;
            }else if(c[j].three>c[j].one && c[j].three>c[j].two){
                g++;
                k=k+c[j].three;
            }
        }
        for(int j=0;j < b;j++){
        	if(e>h){
        		e--;
        		f++;
        		k=k+c[j].two-c[j].one;
			}
        	if(f>h){
        		f--;
        		g++;
        		k=k+c[j].three-c[j].two;
			}	
			if(g>h){
				g--;
				e++;
				k=k+c[j].one-c[j].three;
			}
		}
		ans[l]=k;
		l++;
	}
	for(int i=0;i < l;i++){
		cout << ans[i] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
