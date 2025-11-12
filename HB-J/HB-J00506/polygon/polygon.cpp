#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    
    long long N;
    cin>>N;
    long long n[N];
    for(long long i=0;i<N;i++){
		cin>>n[i];
		}
	long long sum=0;
	if(N>=3){
	for(int a=0;a<N-2;a++){
		for(int b=a+1;b<N-1;b++){
		    for(int c=b+1;c<N;c++){
		        int max=0;
		        if(n[a]>max){
					max=n[a];
					}
				if(n[b]>max){
					max=n[b];
					}
				if(n[c]>max){
					max=n[c];
					}
				if(n[a]+n[b]+n[c]>max*2){
					sum++;
					}
		}
		}
		}
	}
	if(N>=4){
	for(int a=0;a<N-3;a++){
		for(int b=a+1;b<N-2;b++){
		    for(int c=b+1;c<N-1;c++){
				for(int d=c+1;d<N;d++){
		        int max=0;
		        if(n[a]>max){
					max=n[a];
					}
				if(n[b]>max){
					max=n[b];
					}
				if(n[c]>max){
					max=n[c];
					}
				if(n[d]>max){
					max=n[d];
					}
				if(n[a]+n[b]+n[c]+n[d]>max*2){
					sum++;
					}
		}
		}
		}
		}
	}
	if(N>=5){
	for(int a=0;a<N-4;a++){
		for(int b=a+1;b<N-3;b++){
		    for(int c=b+1;c<N-2;c++){
				for(int d=c+1;d<N-1;d++){
					for(int e=d+1;e<N;e++){
		        int max=0;
		        if(n[a]>max){
					max=n[a];
					}
				if(n[b]>max){
					max=n[b];
					}
				if(n[c]>max){
					max=n[c];
					}
				if(n[d]>max){
					max=n[d];
					}
				if(n[e]>max){
					max=n[e];
					}
				if(n[a]+n[b]+n[c]+n[d]+n[e]>max*2){
					sum++;
					}
		}
		}
		}
		}
		}
	}
	if(N>=6){
	for(int a=0;a<N-5;a++){
		for(int b=a+1;b<N-4;b++){
		    for(int c=b+1;c<N-3;c++){
				for(int d=c+1;d<N-2;d++){
					for(int e=d+1;e<N-1;e++){
						for(int f=e+1;f<N;f++){
		        int max=0;
		        if(n[a]>max){
					max=n[a];
					}
				if(n[b]>max){
					max=n[b];
					}
				if(n[c]>max){
					max=n[c];
					}
				if(n[d]>max){
					max=n[d];
					}
				if(n[e]>max){
					max=n[e];
					}
				if(n[f]>max){
					max=n[f];
					}
				if(n[a]+n[b]+n[c]+n[d]+n[e]+n[f]>max*2){
					sum++;
					}
		}
		}
		}
		}
		}
		}
	}
	if(N>=7){
	for(int a=0;a<N-6;a++){
		for(int b=a+1;b<N-5;b++){
		    for(int c=b+1;c<N-4;c++){
				for(int d=c+1;d<N-3;d++){
					for(int e=d+1;e<N-2;e++){
						for(int f=e+1;f<N-1;f++){
							for(int g=f+1;g<N;g++){
		        int max=0;
		        if(n[a]>max){
					max=n[a];
					}
				if(n[b]>max){
					max=n[b];
					}
				if(n[c]>max){
					max=n[c];
					}
				if(n[d]>max){
					max=n[d];
					}
				if(n[e]>max){
					max=n[e];
					}
				if(n[f]>max){
					max=n[f];
					}
				if(n[g]>max){
					max=n[g];
					}
				if(n[a]+n[b]+n[c]+n[d]+n[e]+n[f]+n[g]>max*2){
					sum++;
					}
		}
		}
		}
		}
		}
		}
		}
	}
	if(N>=8){
	for(int a=0;a<N-7;a++){
		for(int b=a+1;b<N-6;b++){
		    for(int c=b+1;c<N-5;c++){
				for(int d=c+1;d<N-4;d++){
					for(int e=d+1;e<N-3;e++){
						for(int f=e+1;f<N-2;f++){
							for(int g=f+1;g<N-1;g++){
								for(int h=g+1;h<N;h++){
		        int max=0;
		        if(n[a]>max){
					max=n[a];
					}
				if(n[b]>max){
					max=n[b];
					}
				if(n[c]>max){
					max=n[c];
					}
				if(n[d]>max){
					max=n[d];
					}
				if(n[e]>max){
					max=n[e];
					}
				if(n[f]>max){
					max=n[f];
					}
				if(n[g]>max){
					max=n[g];
					}
				if(n[h]>max){
					max=n[h];
					}
				if(n[a]+n[b]+n[c]+n[d]+n[e]+n[f]+n[g]+n[h]>max*2){
					sum++;
					}
		}
		}
		}
		}
		}
		}
		}
		}
	}
	if(N>=9){
	for(int a=0;a<N-8;a++){
		for(int b=a+1;b<N-7;b++){
		    for(int c=b+1;c<N-6;c++){
				for(int d=c+1;d<N-5;d++){
					for(int e=d+1;e<N-4;e++){
						for(int f=e+1;f<N-3;f++){
							for(int g=f+1;g<N-2;g++){
								for(int h=g+1;h<N-1;h++){
									for(int i=h+1;i<N;i++){
		        int max=0;
		        if(n[a]>max){
					max=n[a];
					}
				if(n[b]>max){
					max=n[b];
					}
				if(n[c]>max){
					max=n[c];
					}
				if(n[d]>max){
					max=n[d];
					}
				if(n[e]>max){
					max=n[e];
					}
				if(n[f]>max){
					max=n[f];
					}
				if(n[g]>max){
					max=n[g];
					}
				if(n[h]>max){
					max=n[h];
					}
				if(n[i]>max){
					max=n[i];
					}
				if(n[a]+n[b]+n[c]+n[d]+n[e]+n[f]+n[g]+n[h]+n[i]>max*2){
					sum++;
					}
		}
		}
		}
		}
		}
		}
		}
		}
		}
	}
	if(N>=10){
	for(int a=0;a<N-9;a++){
		for(int b=a+1;b<N-8;b++){
		    for(int c=b+1;c<N-7;c++){
				for(int d=c+1;d<N-6;d++){
					for(int e=d+1;e<N-5;e++){
						for(int f=e+1;f<N-4;f++){
							for(int g=f+1;g<N-3;g++){
								for(int h=g+1;h<N-2;h++){
									for(int i=h+1;i<N-1;i++){
										for(int j=i+1;j<N;j++){
		        int max=0;
		        if(n[a]>max){
					max=n[a];
					}
				if(n[b]>max){
					max=n[b];
					}
				if(n[c]>max){
					max=n[c];
					}
				if(n[d]>max){
					max=n[d];
					}
				if(n[e]>max){
					max=n[e];
					}
				if(n[f]>max){
					max=n[f];
					}
				if(n[g]>max){
					max=n[g];
					}
				if(n[h]>max){
					max=n[h];
					}
				if(n[i]>max){
					max=n[i];
					}
				if(n[j]>max){
					max=n[j];
					}
				if(n[a]+n[b]+n[c]+n[d]+n[e]+n[f]+n[g]+n[h]+n[i]+n[j]>max*2){
					sum++;
					}
		}
		}
	    }
		}
		}
		}
		}
		}
		}
		}
	}
	
	
	cout<<sum;
	
    
    return 0;
}





