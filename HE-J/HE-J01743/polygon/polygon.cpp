#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,a[5010]={};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);
	if(n==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=i+2;k<n;k++){if(a[i]+a[j]+a[k]>2*a[k]) sum++;}}}
	}
	if(n==4){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=i+2;k<n;k++){
					for(int b=i+3;b<n;b++){if(a[i]+a[j]+a[k]>2*a[k]) sum++;
										if(a[i]+a[j]+a[k]+a[b]>2*a[b]) sum++;}}}}
	}
	if(n==5){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=i+2;k<n;k++){
					for(int b=i+3;b<n;b++){
						for(int c=i+4;c<n;c++){if(a[i]+a[j]+a[k]>2*a[k]) sum++;
											if(a[i]+a[j]+a[k]+a[b]>2*a[b]) sum++;
											if(a[i]+a[j]+a[k]+a[b]+a[c]>2*a[c]) sum++;}}}}}
	}
	if(n==6){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=i+2;k<n;k++){
					for(int b=i+3;b<n;b++){
						for(int c=i+4;c<n;c++){
							for(int x=i+5;x<n;x++){if(a[i]+a[j]+a[k]>2*a[k]) sum++;
												if(a[i]+a[j]+a[k]+a[b]>2*a[b]) sum++;
												if(a[i]+a[j]+a[k]+a[b]+a[c]>2*a[c]) sum++;
												if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]>2*a[x]) sum++;}}}}}}
	}
	if(n==7){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=i+2;k<n;k++){
					for(int b=i+3;b<n;b++){
						for(int c=i+4;c<n;c++){
							for(int x=i+5;x<n;x++){
								for(int y=i+6;y<n;x++){if(a[i]+a[j]+a[k]>2*a[k]) sum++;
													if(a[i]+a[j]+a[k]+a[b]>2*a[b]) sum++;
													if(a[i]+a[j]+a[k]+a[b]+a[c]>2*a[c]) sum++;
													if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]>2*a[x]) sum++;
													if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]>2*a[y]) sum++;}}}}}}}
	}
	if(n==8){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
					for(int k=i+2;k<n;k++){
						for(int b=i+3;b<n;b++){
							for(int c=i+4;c<n;c++){
								for(int x=i+5;x<n;x++){
									for(int y=i+6;y<n;x++){
										for(int z=i+7;z<n;z++){if(a[i]+a[j]+a[k]>2*a[k]) sum++;
															if(a[i]+a[j]+a[k]+a[b]>2*a[b]) sum++;
															if(a[i]+a[j]+a[k]+a[b]+a[c]>2*a[c]) sum++;
															if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]>2*a[x]) sum++;
															if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]>2*a[y]) sum++;
															if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]+a[z]>2*a[z]) sum++;}}}}}}}}
	}
	if(n==9){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=i+2;k<n;k++){
					for(int b=i+3;b<n;b++){
						for(int c=i+4;c<n;c++){
							for(int x=i+5;x<n;x++){
								for(int y=i+6;y<n;x++){
									for(int z=i+7;z<n;z++){
										for(int m=i+8;m<n;m++){if(a[i]+a[j]+a[k]>2*a[k]) sum++;
															if(a[i]+a[j]+a[k]+a[b]>2*a[b]) sum++;
															if(a[i]+a[j]+a[k]+a[b]+a[c]>2*a[c]) sum++;
															if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]>2*a[x]) sum++;
															if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]>2*a[y]) sum++;
															if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]+a[z]>2*a[z]) sum++;
															if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]+a[z]+a[m]>2*a[m]) sum++;}}}}}}}}}
	}
	if(n==10){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=i+2;k<n;k++){
					for(int b=i+3;b<n;b++){
						for(int c=i+4;c<n;c++){
							for(int x=i+5;x<n;x++){
								for(int y=i+6;y<n;x++){
									for(int z=i+7;z<n;z++){
										for(int m=i+8;m<n;m++){
											for(int q=i+9;q<n;q++){if(a[i]+a[j]+a[k]>2*a[k]) sum++;
																if(a[i]+a[j]+a[k]+a[b]>2*a[b]) sum++;
																if(a[i]+a[j]+a[k]+a[b]+a[c]>2*a[c]) sum++;
																if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]>2*a[x]) sum++;
																if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]>2*a[y]) sum++;
																if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]+a[z]>2*a[z]) sum++;
																if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]+a[z]+a[m]>2*a[m]) sum++;
																if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]+a[z]+a[m]+a[q]>2*a[q]) sum++;}}}}}}}}}}
	}
	if(n==11){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=i+2;k<n;k++){
				for(int b=i+3;b<n;b++){
					for(int c=i+4;c<n;c++){
						for(int x=i+5;x<n;x++){
							for(int y=i+6;y<n;x++){
								for(int z=i+7;z<n;z++){
									for(int m=i+8;m<n;m++){
										for(int q=i+9;q<n;q++){
											for(int p=i+10;p<n;p++){
												if(a[i]+a[j]+a[k]>2*a[k]) sum++;
												if(a[i]+a[j]+a[k]+a[b]>2*a[b]) sum++;
												if(a[i]+a[j]+a[k]+a[b]+a[c]>2*a[c]) sum++;
												if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]>2*a[x]) sum++;
												if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]>2*a[y]) sum++;
												if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]+a[z]>2*a[z]) sum++;
												if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]+a[z]+a[m]>2*a[m]) sum++;
												if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]+a[z]+a[m]+a[q]>2*a[q]) sum++;
												if(a[i]+a[j]+a[k]+a[b]+a[c]+a[x]+a[y]+a[z]+a[m]+a[q]+a[p]>2*a[p]) sum++;}}}}}}}}}}}}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
