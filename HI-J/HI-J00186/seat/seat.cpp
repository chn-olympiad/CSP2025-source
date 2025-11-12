#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0;//nÐÐmÁÐ
	int k=0;
	cin>>n>>m;
	int a[110];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k+=a[1];
	sort(a+0,a+n*m+2,cmp);
	for(int i=1;i<=n*m;i++){
		if(n==1&&m==1){
		    cout<<"1 1";
		    break;
	    }
	    else if(n==1&&m==2){
	    	if(a[1]==k){
	    		cout<<"1 1";
	    		return 0;
			}if(a[2]==k){
	    		cout<<"1 2";
	    		return 0;
			}
		}
		else if(n==1&&m==3){
	    	if(a[1]==k){
	    		cout<<"1 1";
	    		return 0;
			}if(a[2]==k){
	    		cout<<"1 2";
	    		return 0;
			}if(a[3]==k){
	    		cout<<"1 3";
	    		return 0;
			}
		}
		else if(n==1&&m==4){
	    	if(a[1]==k){
	    		cout<<"1 1";
	    		return 0;
			}if(a[2]==k){
	    		cout<<"1 2";
	    		return 0;
			}if(a[3]==k){
	    		cout<<"1 3";
	    		return 0;
			}if(a[4]==k){
	    		cout<<"1 4";
	    		return 0;
			}
		}
		else if(n==1&&m==5){
	    	if(a[1]==k){
	    		cout<<"1 1";
	    		return 0;
			}if(a[2]==k){
	    		cout<<"1 2";
	    		return 0;
			}if(a[3]==k){
	    		cout<<"1 3";
	    		return 0;
			}if(a[4]==k){
	    		cout<<"1 4";
	    		return 0;
			}if(a[5]==k){
	    		cout<<"1 5";
	    		return 0;
			}
		}
		else if(n==1&&m==6){
	    	if(a[1]==k){
	    		cout<<"1 1";
	    		return 0;
			}if(a[2]==k){
	    		cout<<"1 2";
	    		return 0;
			}if(a[3]==k){
	    		cout<<"1 3";
	    		return 0;
			}if(a[4]==k){
	    		cout<<"1 4";
	    		return 0;
			}if(a[5]==k){
	    		cout<<"1 5";
	    		return 0;
			}if(a[6]==k){
	    		cout<<"1 6";
	    		return 0;
			}
		}
		else if(n==1&&m==7){
	    	if(a[1]==k){
	    		cout<<"1 1";
	    		return 0;
			}if(a[2]==k){
	    		cout<<"1 2";
	    		return 0;
			}if(a[3]==k){
	    		cout<<"1 3";
	    		return 0;
			}if(a[4]==k){
	    		cout<<"1 4";
	    		return 0;
			}if(a[5]==k){
	    		cout<<"1 5";
	    		return 0;
			}if(a[6]==k){
	    		cout<<"1 6";
	    		return 0;
			}if(a[7]==k){
	    		cout<<"1 7";
	    		return 0;
			}
		}
		else if(n==1&&m==8){
	    	if(a[1]==k){
	    		cout<<"1 1";
	    		return 0;
			}if(a[2]==k){
	    		cout<<"1 2";
	    		return 0;
			}if(a[3]==k){
	    		cout<<"1 3";
	    		return 0;
			}if(a[4]==k){
	    		cout<<"1 4";
	    		return 0;
			}if(a[5]==k){
	    		cout<<"1 5";
	    		return 0;
			}if(a[6]==k){
	    		cout<<"1 6";
	    		return 0;
			}if(a[7]==k){
	    		cout<<"1 7";
	    		return 0;
			}if(a[8]==k){
	    		cout<<"1 8";
	    		return 0;
			}
		}
		else if(n==1&&m==9){
	    	if(a[1]==k){
	    		cout<<"1 1";
	    		return 0;
			}if(a[2]==k){
	    		cout<<"1 2";
	    		return 0;
			}if(a[3]==k){
	    		cout<<"1 3";
	    		return 0;
			}if(a[4]==k){
	    		cout<<"1 4";
	    		return 0;
			}if(a[5]==k){
	    		cout<<"1 5";
	    		return 0;
			}if(a[6]==k){
	    		cout<<"1 6";
	    		return 0;
			}if(a[7]==k){
	    		cout<<"1 7";
	    		return 0;
			}if(a[8]==k){
	    		cout<<"1 8";
	    		return 0;
			}if(a[9]==k){
	    		cout<<"1 9";
	    		return 0;
			}
		}
	    else if(n==1&&m==10){
	    	if(a[1]==k){
	    		cout<<"1 1";
	    		return 0;
			}if(a[2]==k){
	    		cout<<"1 2";
	    		return 0;
			}if(a[3]==k){
	    		cout<<"1 3";
	    		return 0;
			}if(a[4]==k){
	    		cout<<"1 4";
	    		return 0;
			}if(a[5]==k){
	    		cout<<"1 5";
	    		return 0;
			}if(a[6]==k){
	    		cout<<"1 6";
	    		return 0;
			}if(a[7]==k){
	    		cout<<"1 7";
	    		return 0;
			}if(a[8]==k){
	    		cout<<"1 8";
	    		return 0;
			}if(a[9]==k){
	    		cout<<"1 9";
	    		return 0;
			}if(a[10]==k){
	    		cout<<"1 10";
	    		return 0;
			}
		}
		else if(n==2&&m==1){
	    	if(a[1]==k){
	    		cout<<"1 1";
	    		return 0;
			}if(a[2]==k){
	    		cout<<"2 1";
	    		return 0;
			}
		}
		else if(n==2&&m==2){
			if(a[1]==k){
			    cout<<"1 1";
			    return 0;
		    }if(a[2]==k){
		    	cout<<"1 2";
		    	return 0;
		    }if(a[3]==k){
		    	cout<<"2 2";
		   	    return 0;
		    }if(a[4]==k){
			    cout<<"2 1";
			    return 0;
		    }
		}
		else if(n==2&&m==3){
			if(a[1]==k){
			    cout<<"1 1";
			    return 0;
		    }if(a[2]==k){
		    	cout<<"1 2";
		    	return 0;
		    }if(a[3]==k){
		    	cout<<"1 3";
		   	    return 0;
		    }if(a[4]==k){
			    cout<<"2 3";
			    return 0;
		    }if(a[5]==k){
			    cout<<"2 2";
			    return 0;
		    }if(a[6]==k){
			    cout<<"2 1";
			    return 0;
		    }
		}
		else if(n==2&&m==4){
			if(a[1]==k){
			    cout<<"1 1";
			    return 0;
		    }if(a[2]==k){
		    	cout<<"1 2";
		    	return 0;
		    }if(a[3]==k){
		    	cout<<"1 3";
		   	    return 0;
		    }if(a[4]==k){
			    cout<<"1 4";
			    return 0;
		    }if(a[5]==k){
			    cout<<"2 4";
			    return 0;
		    }if(a[6]==k){
			    cout<<"2 3";
			    return 0;
		    }if(a[7]==k){
			    cout<<"2 2";
			    return 0;
		    }if(a[8]==k){
			    cout<<"2 1";
			    return 0;
		    }
		}
		else if(n==2&&m==5){
			if(a[1]==k){
			    cout<<"1 1";
			    return 0;
		    }if(a[2]==k){
		    	cout<<"1 2";
		    	return 0;
		    }if(a[3]==k){
		    	cout<<"1 3";
		   	    return 0;
		    }if(a[4]==k){
			    cout<<"1 4";
			    return 0;
		    }if(a[5]==k){
			    cout<<"1 5";
			    return 0;
		    }if(a[6]==k){
			    cout<<"2 5";
			    return 0;
		    }if(a[7]==k){
			    cout<<"2 4";
			    return 0;
		    }if(a[8]==k){
			    cout<<"2 3";
			    return 0;
		    }if(a[9]==k){
			    cout<<"2 2";
			    return 0;
		    }if(a[10]==k){
			    cout<<"2 1";
			    return 0;
		    }
		}
		else if(n==2&&m==6){
			if(a[1]==k){
			    cout<<"1 1";
			    return 0;
		    }if(a[2]==k){
		    	cout<<"1 2";
		    	return 0;
		    }if(a[3]==k){
		    	cout<<"1 3";
		   	    return 0;
		    }if(a[4]==k){
			    cout<<"1 4";
			    return 0;
		    }if(a[5]==k){
			    cout<<"1 5";
			    return 0;
		    }if(a[6]==k){
			    cout<<"1 6";
			    return 0;
		    }if(a[7]==k){
			    cout<<"2 6";
			    return 0;
		    }if(a[8]==k){
			    cout<<"2 5";
			    return 0;
		    }if(a[9]==k){
			    cout<<"2 4";
			    return 0;
		    }if(a[10]==k){
			    cout<<"2 3";
			    return 0;
		    }if(a[11]==k){
			    cout<<"2 2";
			    return 0;
		    }if(a[12]==k){
			    cout<<"2 1";
			    return 0;
		    }
		}
		else if(n==2&&m==7){
			if(a[1]==k){
			    cout<<"1 1";
			    return 0;
		    }if(a[2]==k){
		    	cout<<"1 2";
		    	return 0;
		    }if(a[3]==k){
		    	cout<<"1 3";
		   	    return 0;
		    }if(a[4]==k){
			    cout<<"1 4";
			    return 0;
		    }if(a[5]==k){
			    cout<<"1 5";
			    return 0;
		    }if(a[6]==k){
			    cout<<"1 6";
			    return 0;
		    }if(a[7]==k){
			    cout<<"1 7";
			    return 0;
		    }if(a[8]==k){
			    cout<<"2 7";
			    return 0;
		    }if(a[9]==k){
			    cout<<"2 6";
			    return 0;
		    }if(a[10]==k){
			    cout<<"2 5";
			    return 0;
		    }if(a[11]==k){
			    cout<<"2 4";
			    return 0;
		    }if(a[12]==k){
			    cout<<"2 3";
			    return 0;
		    }if(a[13]==k){
			    cout<<"2 2";
			    return 0;
		    }if(a[14]==k){
			    cout<<"2 1";
			    return 0;
		    }
		}
		else if(n==2&&m==8){
			if(a[1]==k){
			    cout<<"1 1";
			    return 0;
		    }if(a[2]==k){
		    	cout<<"1 2";
		    	return 0;
		    }if(a[3]==k){
		    	cout<<"1 3";
		   	    return 0;
		    }if(a[4]==k){
			    cout<<"1 4";
			    return 0;
		    }if(a[5]==k){
			    cout<<"1 5";
			    return 0;
		    }if(a[6]==k){
			    cout<<"1 6";
			    return 0;
		    }if(a[7]==k){
			    cout<<"1 7";
			    return 0;
		    }if(a[8]==k){
			    cout<<"1 8";
			    return 0;
		    }if(a[9]==k){
			    cout<<"2 8";
			    return 0;
		    }if(a[10]==k){
			    cout<<"2 7";
			    return 0;
		    }if(a[11]==k){
			    cout<<"2 6";
			    return 0;
		    }if(a[12]==k){
			    cout<<"2 5";
			    return 0;
		    }if(a[13]==k){
			    cout<<"2 4";
			    return 0;
		    }if(a[14]==k){
			    cout<<"2 3";
			    return 0;
		    }if(a[15]==k){
			    cout<<"2 2";
			    return 0;
		    }if(a[16]==k){
			    cout<<"2 1";
			    return 0;
		    }
		}
		else if(n==2&&m==9){
			if(a[1]==k){
			    cout<<"1 1";
			    return 0;
		    }if(a[2]==k){
		    	cout<<"1 2";
		    	return 0;
		    }if(a[3]==k){
		    	cout<<"1 3";
		   	    return 0;
		    }if(a[4]==k){
			    cout<<"1 4";
			    return 0;
		    }if(a[5]==k){
			    cout<<"1 5";
			    return 0;
		    }if(a[6]==k){
			    cout<<"1 6";
			    return 0;
		    }if(a[7]==k){
			    cout<<"1 7";
			    return 0;
		    }if(a[8]==k){
			    cout<<"1 8";
			    return 0;
		    }if(a[9]==k){
			    cout<<"1 9";
			    return 0;
		    }if(a[10]==k){
			    cout<<"2 9";
			    return 0;
		    }if(a[11]==k){
			    cout<<"2 8";
			    return 0;
		    }if(a[12]==k){
			    cout<<"2 7";
			    return 0;
		    }if(a[13]==k){
			    cout<<"2 6";
			    return 0;
		    }if(a[14]==k){
			    cout<<"2 5";
			    return 0;
		    }if(a[15]==k){
			    cout<<"2 4";
			    return 0;
		    }if(a[16]==k){
			    cout<<"2 3";
			    return 0;
		    }if(a[17]==k){
			    cout<<"2 2";
			    return 0;
		    }if(a[18]==k){
			    cout<<"2 1";
			    return 0;
		    }
		}
		else if(n==2&&m==10){
			if(a[1]==k){
	    		cout<<"1 1";
	    		return 0;
			}if(a[2]==k){
	    		cout<<"1 2";
	    		return 0;
			}if(a[3]==k){
	    		cout<<"1 3";
	    		return 0;
			}if(a[4]==k){
	    		cout<<"1 4";
	    		return 0;
			}if(a[5]==k){
	    		cout<<"1 5";
	    		return 0;
			}if(a[6]==k){
	    		cout<<"1 6";
	    		return 0;
			}if(a[7]==k){
	    		cout<<"1 7";
	    		return 0;
			}if(a[8]==k){
	    		cout<<"1 8";
	    		return 0;
			}if(a[9]==k){
	    		cout<<"1 9";
	    		return 0;
			}if(a[10]==k){
	    		cout<<"1 10";
	    		return 0;
			}if(a[11]==k){
	    		cout<<"2 10";
	    		return 0;
			}if(a[12]==k){
	    		cout<<"2 9";
	    		return 0;
			}if(a[13]==k){
	    		cout<<"2 8";
	    		return 0;
			}if(a[14]==k){
	    		cout<<"2 7";
	    		return 0;
			}if(a[15]==k){
	    		cout<<"2 6";
	    		return 0;
			}if(a[16]==k){
	    		cout<<"2 5";
	    		return 0;
			}if(a[17]==k){
	    		cout<<"2 4";
	    		return 0;
			}if(a[18]==k){
	    		cout<<"2 3";
	    		return 0;
			}if(a[19]==k){
	    		cout<<"2 2";
	    		return 0;
			}if(a[20]==k){
	    		cout<<"2 1";
	    		return 0;
			}
		}
		else if(n==3&&m==3){
			if(a[1]==k){
			    cout<<"1 1";
			    return 0;
		    }if(a[2]==k){
		    	cout<<"1 2";
		    	return 0;
		    }if(a[3]==k){
		    	cout<<"1 3";
		   	    return 0;
		    }if(a[4]==k){
			    cout<<"2 3";
			    return 0;
		    }if(a[5]==k){
			    cout<<"2 2";
			    return 0;
		    }if(a[6]==k){
			    cout<<"2 1";
			    return 0;
		    }if(a[7]==k){
			    cout<<"3 1";
			    return 0;
		    }if(a[8]==k){
			    cout<<"3 2";
			    return 0;
		    }if(a[9]==k){
			    cout<<"3 3";
			    return 0;
		    }
		else if(n==10&&m==1){
			if(a[1]==k){
	    		cout<<"1 1";
	    		return 0;
			}if(a[2]==k){
	    		cout<<"2 1";
	    		return 0;
			}if(a[3]==k){
	    		cout<<"3 1";
	    		return 0;
			}if(a[4]==k){
	    		cout<<"4 1";
	    		return 0;
			}if(a[5]==k){
	    		cout<<"5 1";
	    		return 0;
			}if(a[6]==k){
	    		cout<<"6 1";
	    		return 0;
			}if(a[7]==k){
	    		cout<<"7 1";
	    		return 0;
			}if(a[8]==k){
	    		cout<<"8 1";
	    		return 0;
			}if(a[9]==k){
	    		cout<<"9 1";
	    		return 0;
			}if(a[10]==k){
	    		cout<<"10 1";
	    		return 0;
			}
		}
		else if(n==10&&n==2){
			if(a[1]==k){
	    		cout<<"1 1";
	    		return 0;
			}if(a[2]==k){
	    		cout<<"2 1";
	    		return 0;
			}if(a[3]==k){
	    		cout<<"3 1";
	    		return 0;
			}if(a[4]==k){
	    		cout<<"4 1";
	    		return 0;
			}if(a[5]==k){
	    		cout<<"5 1";
	    		return 0;
			}if(a[6]==k){
	    		cout<<"6 1";
	    		return 0;
			}if(a[7]==k){
	    		cout<<"7 1";
	    		return 0;
			}if(a[8]==k){
	    		cout<<"8 1";
	    		return 0;
			}if(a[9]==k){
	    		cout<<"9 1";
	    		return 0;
			}if(a[10]==k){
	    		cout<<"10 1";
	    		return 0;
			}if(a[11]==k){
	    		cout<<"2 10";
	    		return 0;
			}if(a[12]==k){
	    		cout<<"2 9";
	    		return 0;
			}if(a[13]==k){
	    		cout<<"2 8";
	    		return 0;
			}if(a[14]==k){
	    		cout<<"2 7";
	    		return 0;
			}if(a[15]==k){
	    		cout<<"2 6";
	    		return 0;
			}if(a[16]==k){
	    		cout<<"2 5";
	    		return 0;
			}if(a[17]==k){
	    		cout<<"2 4";
	    		return 0;
			}if(a[18]==k){
	    		cout<<"2 3";
	    		return 0;
			}if(a[19]==k){
	    		cout<<"2 2";
	    		return 0;
			}if(a[20]==k){
	    		cout<<"2 1";
	    		return 0;
			}
		}
	}
	return 0;
}
}
