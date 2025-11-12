#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	int n;
	scanf ("%d", &n);
	for (int i=1; i<=n; i++)
		scanf ("%d", &a[i]);
	int ans = 0;
	sort (a + 1, a + 1 + n);
	if (n < 3) {
		printf ("0\n");
		return 0;
	}
	if (n == 3) {
		if ((a[1] + a[2] + a[3]) > (2 * a[3])) printf ("1\n");
		return 0;
	}
	if (n == 4) {
		for (int i=1; i<=n-2; i++) 
			for (int j=i+1; j<=n-1; j++) 
				for (int k=j+1; k<=n; k++) 
					if ((a[i] + a[j] + a[k]) > (a[k] * 2)) ans++;
		if ((a[1] + a[2] + a[3] + a[4]) > (a[4] * 2)) {
			printf ("%d\n", ans + 1);
			return 0;
		}
		else {
			printf ("%d\n", ans);
			return 0;
		}
	}
	if (n == 5) {
		for (int i=1; i<=n-2; i++) 
			for (int j=i+1; j<=n-1; j++) 
				for (int k=j+1; k<=n; k++) 
					if ((a[i] + a[j] + a[k]) > (a[k] * 2)) ans++;
		for (int i=1; i<=n-3; i++) 
			for (int j=i+1; j<=n-2; j++) 
				for (int k=j+1; k<=n-1; k++) 
					for (int l=k+1; l<=n; l++) 
						if ((a[i] + a[j] + a[k] + a[l]) > (a[l] * 2)) ans++;
		if ((a[1] + a[2] + a[3] + a[4] + a[5]) > (a[5] * 2)) {
			printf ("%d\n", ans + 1);
			return 0;
		}
		else {
			printf ("%d\n", ans);
			return 0;
		}
	}
	if (n == 6) {
		for (int i=1; i<=n-2; i++) 
			for (int j=i+1; j<=n-1; j++) 
				for (int k=j+1; k<=n; k++) 
					if ((a[i] + a[j] + a[k]) > (a[k] * 2)) ans++;
		for (int i=1; i<=n-3; i++) 
			for (int j=i+1; j<=n-2; j++) 
				for (int k=j+1; k<=n-1; k++) 
					for (int l=k+1; l<=n; l++) 
						if ((a[i] + a[j] + a[k] + a[l]) > (a[l] * 2)) ans++;
		for (int i=1; i<=n-4; i++) 
			for (int j=i+1; j<=n-3; j++) 
				for (int k=j+1; k<=n-2; k++) 
					for (int l=k+1; l<=n-1; l++) 
						for (int z=l+1; z<=n; z++)
							if ((a[i] + a[j] + a[k] + a[l] + a[z]) > (a[z] * 2)) ans++;
		if ((a[1] + a[2] + a[3] + a[4] + a[5] + a[6]) > (a[6] * 2)) {
			printf ("%d\n", ans + 1);
			return 0;
		}
		else {
			printf ("%d\n", ans);
			return 0;
		}
	}
	if (n == 7) {
		for (int i=1; i<=n-2; i++) 
			for (int j=i+1; j<=n-1; j++) 
				for (int k=j+1; k<=n; k++) 
					if ((a[i] + a[j] + a[k]) > (a[k] * 2)) ans++;
		for (int i=1; i<=n-3; i++) 
			for (int j=i+1; j<=n-2; j++) 
				for (int k=j+1; k<=n-1; k++) 
					for (int l=k+1; l<=n; l++) 
						if ((a[i] + a[j] + a[k] + a[l]) > (a[l] * 2)) ans++;
		for (int i=1; i<=n-4; i++) 
			for (int j=i+1; j<=n-3; j++) 
				for (int k=j+1; k<=n-2; k++) 
					for (int l=k+1; l<=n-1; l++) 
						for (int z=l+1; z<=n; z++)
							if ((a[i] + a[j] + a[k] + a[l] + a[z]) > (a[z] * 2)) ans++;
		for (int i=1; i<=n-5; i++) 
			for (int j=i+1; j<=n-4; j++) 
				for (int k=j+1; k<=n-3; k++) 
					for (int l=k+1; l<=n-2; l++) 
						for (int z=l+1; z<=n-1; z++)
							for (int u=z+1; u<=n; u++)
								if ((a[i] + a[j] + a[k] + a[l] + a[z] + a[u]) > (a[u] * 2)) ans++;
		if ((a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7]) > (a[7] * 2)) {
			printf ("%d\n", ans + 1);
			return 0;
		}
		else {
			printf ("%d\n", ans);
			return 0;
		}
	}
	if (n == 8) {
		for (int i=1; i<=n-2; i++) 
			for (int j=i+1; j<=n-1; j++) 
				for (int k=j+1; k<=n; k++) 
					if ((a[i] + a[j] + a[k]) > (a[k] * 2)) ans++;
		for (int i=1; i<=n-3; i++) 
			for (int j=i+1; j<=n-2; j++) 
				for (int k=j+1; k<=n-1; k++) 
					for (int l=k+1; l<=n; l++) 
						if ((a[i] + a[j] + a[k] + a[l]) > (a[l] * 2)) ans++;
		for (int i=1; i<=n-4; i++) 
			for (int j=i+1; j<=n-3; j++) 
				for (int k=j+1; k<=n-2; k++) 
					for (int l=k+1; l<=n-1; l++) 
						for (int z=l+1; z<=n; z++)
							if ((a[i] + a[j] + a[k] + a[l] + a[z]) > (a[z] * 2)) ans++;
		for (int i=1; i<=n-5; i++) 
			for (int j=i+1; j<=n-4; j++) 
				for (int k=j+1; k<=n-3; k++) 
					for (int l=k+1; l<=n-2; l++) 
						for (int z=l+1; z<=n-1; z++)
							for (int u=z+1; u<=n; u++)
								if ((a[i] + a[j] + a[k] + a[l] + a[z] + a[u]) > (a[u] * 2)) ans++;
		for (int i=1; i<=n-6; i++) 
			for (int j=i+1; j<=n-5; j++) 
				for (int k=j+1; k<=n-4; k++) 
					for (int l=k+1; l<=n-3; l++) 
						for (int z=l+1; z<=n-2; z++)
							for (int u=z+1; u<=n-1; u++)
								for (int y=u+1; y<=n; y++)
									if ((a[i] + a[j] + a[k] + a[l] + a[z] + a[u] + a[y]) > (a[y] * 2)) ans++;
		if ((a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8]) > (a[8] * 2)) {
			printf ("%d\n", ans + 1);
			return 0;
		}
		else {
			printf ("%d\n", ans);
			return 0;
		}
	}
	return 0;
}
